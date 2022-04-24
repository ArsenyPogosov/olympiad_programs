#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int N = 1003;

struct gate
{
	int y, x1, x2, c;
	gate(int y = 0, int x1 = 0, int x2 = 0, int c = 0) : y(y), x1(x1), x2(x2), c(c) {};

	friend istream& operator>>(istream& in, gate& g)
	{
		in >> g.x1 >> g.x2 >> g.y >> g.c;
		g.y = -g.y;
		return in;
	}

	bool operator<(gate b)
	{
		return y < b.y;
	}
};

int vprod(int x1, int  y1, int  x2, int  y2)
{
	return x1 * y2 - x2 * y1;
}

bool intersect(int ax, int ay, int  bx, int  by, int  cx, int  cy, int  dx, int  dy)
{
	int h1 = vprod(bx - ax, by - ay, cx - ax, cy - ay), h2 = vprod(bx - ax, by - ay, dx - ax, dy - ay);

	return (h1 <= 0 && h2 >= 0) || (h2 <= 0 && h1 >= 0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, sx, sy, fx, fy; cin >> n >> sx >> sy >> fx >> fy;
	sy = -sy; fy = -fy;

	vector<gate> g(n);
	for (auto& i : g) 
		cin >> i;
	sort(g.begin(), g.end());

	int x[N], ttx = 0, y[N], tty = 0, ttdp = 0;
	double dp[N];
	x[ttx++] = sx; y[tty++] = sy; dp[ttdp++] = 0;
	for (auto& i : g)
		dp[0] += i.c;

	auto add = [&](int tx, int ty)
	{
		x[ttx++] = tx; y[tty++] = ty; dp[ttdp++] = 1e18;

		for (int j = 0; y[j] < ty; ++j)
		{
			double td = dp[j] + hypot(x[j] - tx, y[j] - ty);

			for (auto& k : g)
			{
				if (k.y <= y[j]) continue;
				if (k.y > ty) break;

				if (intersect(x[j], y[j], tx, ty, k.x1, k.y, k.x2, k.y))
					td -= k.c;
			}

			dp[ttdp - 1] = min(dp[ttdp - 1], td);
		}
	};

	for (auto& i : g)
		for (int h = 0; h < 2; ++h)
			add((h ? i.x2 : i.x1), i.y);
	add(fx, fy);

	cout << fixed << setprecision(4) << dp[ttdp - 1] << '\n';

	return 0;
}