#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

__int128 n, m, X, Y;

pair<pair<__int128, __int128>, __int128> nxt(__int128 x, __int128 y, __int128 c)
{
	if (c == 0)
	{
		if (x > 0)
			return { {x - 1, y}, 0 };
		return { {x + 1, y}, 2 };
	}
	if (c == 1)
	{
		if (y < m - 1)
			return { {x, y + 1}, 1 };
		return { {x, y - 1}, 3 };
	}
	if (c == 2)
	{
		if (x < n - 1)
			return { {x + 1, y}, 2 };
		return { {x - 1, y}, 0 };
	}
	if (c == 3)
	{
		if (y > 0)
			return { {x, y - 1}, 3 };
		return { {x, y + 1}, 1 };
	}
}

vector<pair<__int128, __int128>> adj(__int128 x, __int128 y)
{
	vector<pair<__int128, __int128>> res, step{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
	for (auto& i : step)
	{
		__int128 nx = x + i.first, ny = y + i.second;
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			res.emplace_back(nx, ny);
	}
	return res;
}

__int128 GGGCD(__int128 a, __int128 b)
{
	return (b ? GGGCD(b, a % b) : a);
}

pair<__int128, __int128> GCD(__int128 a, __int128 b)
{
	if (b == 0) return { 1, 0 };
	auto res = GCD(b, a % b);
	return { res.second, res.first - res.second * (a / b) };
}

pair<__int128, __int128> mergeres(__int128 t1, __int128 p1, __int128 t2, __int128 p2)
{
	if (min(t1, t2) == -1) return { -1, -1 };
	if (p1 == -1 && p2 == -1)
	{
		if (t1 == t2) return { t1, -1 };
		return { -1, -1 };
	}
	if (p2 == -1) { swap(t1, t2); swap(p1, p2); }
	if (p1 == -1)
	{
		__int128 t = t1 - t2;
		if (t < 0) return { -1, -1 };
		if (t % p2 == 0)
			return { t1, -1 };
		return { -1, -1 };
	}

	//t1 + k1*p1 == t2 + k2*p2
	//t2 - t1 == k1*p1 - k2*p2 / d
	__int128 targ = t2 - t1;
	auto h = GCD(p1, p2);
	__int128 k1 = h.first, k2 = -h.second, d = GGGCD(p1, p2);
	if (targ % d != 0) return { -1, -1 };
	targ /= d; p1 /= d; p2 /= d;
	k1 *= targ; k2 *= targ;
	__int128 resp = p1 * p2 * d;
	//k1 == k1 + x*p2
	//k2 == k2 + x*p1
	__int128 x1 = (-k1) / p2 - 5;
	while (x1 * p2 + k1 < 0) ++x1;
	__int128 x2 = (-k2) / p1 - 5;
	while (x2 * p1 + k2 < 0) ++x2;
	__int128 x = max(x1, x2);
	__int128 rest = t1 + (k1 + x * p2) * p1 * d;
	return { rest, resp };
}

vector<vector<__int128>> table;

vector<vector<vector<__int128>>> used, type, tto;

pair<__int128, __int128> getinf(__int128 x, __int128 y, __int128 c)
{
	if (used[x][y][c] == 2) return { type[x][y][c], tto[x][y][c] };
	used[x][y][c] = 1;
	auto h = nxt(x, y, (c + table[x][y]) % 4);
	__int128 nx = h.first.first, ny = h.first.second, nc = h.second;
	if (nx == X && ny == Y)
	{
		type[x][y][c] = nc;
		tto[x][y][c] = 1;
	}
	else
		if (used[nx][ny][nc] != 1)
		{
			auto res = getinf(nx, ny, nc);
			type[x][y][c] = res.first;
			if (res.first == -1)
				tto[x][y][c] = -1;
			else
				tto[x][y][c] = res.second + 1;
		}
	used[x][y][c] = 2;
	return { type[x][y][c], tto[x][y][c] };
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	/*while (true)
	{
		__int128 t1, p1, t2, p2;
		cin >> t1 >> p1 >> t2 >> p2;
		auto res = mergeres(t1, p1, t2, p2);
		cout << res.first << ' ' << res.second << '\n';
	}*/
	int n1, m1, k1; cin >> n1 >> m1 >> k1;
	__int128 k; n = n1; m = m1; k = k1;
	int X1, Y1; cin >> X1 >> Y1; X = X1; Y = Y1;
	--X; --Y;
	vector<vector<pair<__int128, __int128>>> tend(k, vector<pair<__int128, __int128>>(4, { -1, -1 }));

	table.assign(n, vector<__int128>(m, 0)); 
	for (__int128 iii = 0; iii < k; ++iii)
	{
		int fx1, fy1;
		__int128 fx, fy, fc; char u; cin >> fx1 >> fy1 >> u; 
		fx = fx1; fy = fy1; --fx; --fy;
		if (u == 'U') fc = 0;
		if (u == 'R') fc = 1;
		if (u == 'D') fc = 2;
		if (u == 'L') fc = 3;

		for (auto& i : table)
			for (auto& j : i)
			{
				char h; cin >> h;
				j = (h - '0') % 4;
			}
		used.assign(n, vector<vector<__int128>>(m, vector<__int128>(4, 0)));
		type.assign(n, vector<vector<__int128>>(m, vector<__int128>(4, -1)));
		tto.assign(n, vector<vector<__int128>>(m, vector<__int128>(4, -1)));
		for (__int128 i = 0; i < n; ++i)
			for (__int128 j = 0; j < m; ++j)
				for (__int128 c = 0; c < 4; ++c)
					getinf(i, j, c);
		__int128 tt = 0, tc = fc;
		if (fx != X || fy != Y)
		{
			if (type[fx][fy][fc] == -1) continue;
			tt = tto[fx][fy][fc];
			tc = type[fx][fy][fc];
		}
		while (true)
		{
			if (tend[iii][tc].first == -1)
			{
				tend[iii][tc].first = tt;
			}
			else
			{
				if (tend[iii][tc].second == -1)
					tend[iii][tc].second = tt - tend[iii][tc].first;
				else
					break;
			}
			if (type[X][Y][tc] == -1) break;
			tt += tto[X][Y][tc];
			tc = type[X][Y][tc];
		}
	}
	__int128 res = (__int128)(9e18);
	vector<__int128> cc(5);
	vector<pair<__int128, __int128>> tres = tend[0];
	for (__int128 i = 1; i < k; ++i)
	{
		vector<pair<__int128, __int128>> ttres;
		for (auto& a : tres)
			for (auto& b : tend[i])
				ttres.push_back(mergeres(a.first, a.second, b.first, b.second));
		tres = ttres;
	}
	for (auto& i : tres)
		if (i.first >= 0)
			res = min(res, i.first);
	cout << (res < (__int128)(9e18) ? (long long)(res) : -1) << '\n';

	return 0;
}