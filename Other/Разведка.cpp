#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n = 5400, m = 10800;
double r, pi = atan2(0, -1);

set<pair<int, int>> was;

void add(int x, int y)
{
	if (y > m)
		y -= m * 2;
	if (y <= -m)
		y += m * 2;

	was.emplace(x, y);
}

double area(int x)
{
	if (x <= 0) x = -x + 1;
	return ((2 * pi * r * r * (1 - cos((1 - double(x - 1) / n) * pi / 2))) -
		(2 * pi * r * r * (1 - cos((1 - double(x) / n) * pi / 2)))) / (x == n ? 1 : m * 2);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int x, y, c; cin >> x >> y >> r; c = 0;

	add(x - 1, y - 1);
	add(x - 1, y);
	add(x, y - 1);
	add(x, y);
	char h;
	while (h = cin.get())
	{
		if (h == 'S') break;
		if (h == ' ') continue;

		int cnt = 1;
		if ('0' <= h && h <= '9')
		{
			string ts; ts += h;
			while (h = cin.get())
			{
				if (h == ' ') break;
				ts += h;
			}

			cnt = atoi(ts.c_str());
			cin >> h;
		}

		if (h == 'L')
			c = (c + cnt) % 4;
		if (h == 'R')
			c = ((c - cnt) % 4 + 4) % 4;
		if (h == 'F')
		{
			while (cnt--)
			{
				if (c == 0)
					++x;
				if (c == 1)
					--y;
				if (c == 2)
					--x;
				if (c == 3)
					++y;

				if (y > m)
					y -= m * 2;
				if (y <= -m)
					y += m * 2;

				if (abs(x) != 5400)
				{
					add(x - 1, y - 1);
					add(x - 1, y);
					add(x, y - 1);
					add(x, y);

					continue;
				}

				if (c == 0) c = 2;
				else if (c == 2) c = 0;

				add(x + (x < 0), 0);
			}
		}
	}

	int cnt = 0;
	bool flag1, flag2; flag1 = flag2 = false;
	double ar = 0;
	for (auto& i : was)
	{
		if (i.first == -n)
			flag1 = true;
		else if (i.first == n)
			flag2 = true;
		else
			++cnt, ar += area(i.first);
	}
	cnt += flag1;
	cnt += flag2;
	if (flag1)
		ar += area(n);
	if (flag2)
		ar += area(n);

	cout << cnt << ' ' << fixed << setprecision(16) << ar << '\n';

	return 0;
}