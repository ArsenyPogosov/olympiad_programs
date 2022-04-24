#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> lg2(101);
int n, m, k, p;
vector<vector<int>> mp;

map<pair<pair<int, int>, pair<int, int>>, int> ans;

int Ans(int t, int i, int j, int mask)
{
	int aslkdfasdf = ans[{ {t, i}, { j, mask }}];
	if (aslkdfasdf != 0) return aslkdfasdf;

	if (t == 0) return mp[i][j];

	vector<int> x(4), y(4), d(4, p);
	x[0] = i - 1; y[0] = j + 0;
	x[1] = i + 0; y[1] = j - 1;
	x[2] = i + 1; y[2] = j + 0;
	x[3] = i + 0; y[3] = j + 1;

	int tx = i, ty = j, tmask = mask;
	for (int h = 0; h < p; ++h)
	{
		int c = tmask % 4; tmask /= 4;
		if (c == 0)
			++tx;
		if (c == 1)
			++ty;
		if (c == 2)
			--tx;
		if (c == 3)
			--ty;

		for (int dir = 0; dir < 4; ++dir)
			if (tx == x[dir] && ty == y[dir])
				d[dir] = min(d[dir], h);
	}

	int ress = 0;
	int cutmask = (mask & ((1 << (p * 2 - 2)) - 1)) << 2;
	for (int dir = 0; dir < 4; ++dir)
		if (0 <= x[dir] && x[dir] < n && 0 <= y[dir] && y[dir] < m)
			if (d[dir] >= lg2[mp[x[dir]][y[dir]]])
				ress = max(ress, Ans(t - 1, x[dir], y[dir], cutmask + dir) + mp[i][j]);

	return ans[{ {t, i}, { j, mask }}] = ress;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 1; (1 << (i - 1)) + 1 <= 100; ++i)
		for (int j = (1 << (i - 1)) + 1; j <= (1 << i) && j <= 100; ++j)
			lg2[j] = i;

	cin >> n >> m >> k;
	mp.assign(n, vector<int>(m, 0));

	p = 1;
	for (auto& i : mp)
		for (auto& j : i)
			cin >> j, p = max(p, lg2[j]);
	int mxmask = (1 << (p * 2));

	cout << Ans(k - 1, 0, 0, mxmask - 1) << '\n';

	return 0;
}