#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct stone
{
	int x, y, c;
	stone(int x = 0, int y = 0, int c = 0) : x(x), y(y), c(c) {}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int res = 0;
	vector<stone> stn;

	int c = -1;
	while (true)
	{
		int x, y; cin >> x >> y; c = -c;
		if (x == -1 && y == -1)
			break;

		int lx = -1, rx = n + 1, ly = -1, ry = m + 1;
		for (auto& i : stn)
			if (i.c == c)
			{
				if (i.y == y)
				{
					if (i.x < x && x - lx > x - i.x)
						lx = i.x;
					if (i.x > x && rx - x > i.x - x)
						rx = i.x;
				}
				if (i.x == x)
				{
					if (i.y < y && y - ly > y - i.y)
						ly = i.y;
					if (i.y > y && ry - y > i.y - y)
						ry = i.y;
				}
			}
		if (lx == -1) lx = x; else ++lx;
		if (rx == n + 1) rx = x; else --rx;
		if (ly == -1) ly = y; else ++ly;
		if (ry == m + 1) ry = y; else --ry;
		vector<stone> nstn;
		for (int i = lx; i <= rx; ++i)
			nstn.emplace_back(i, y, c);
		for (int i = ly; i < y; ++i)
			nstn.emplace_back(x, i, c);
		for (int i = y + 1; i <= ry; ++i)
			nstn.emplace_back(x, i, c);
		res = c * (rx - lx + 1 + ry - ly + 1 - 1);
		for (auto& j : stn)
		{
			if (j.x == x && ly <= j.y && j.y <= ry)
				continue;
			if (j.y == y && lx <= j.x && j.x <= rx)
				continue;
			nstn.push_back(j);
			res += j.c;
		}
		stn = nstn;
		cout << res << endl;
	}

	return 0;
}