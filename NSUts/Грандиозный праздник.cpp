#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = int(1e9) + 9, anti2 = 5 * int(1e8) + 5;

int get(int mask, int i)
{
	return (mask & (1 << i));
}

vector<vector<int>> a;

vector<vector<int>> mult(vector<vector<int>> x, vector<vector<int>> y)
{
	int l = x.size(), k = y.size(), r = y[0].size();
	vector<vector<int>> res(l, vector<int>(r));
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < k; ++j)
			for (int f = 0; f < r; ++f)
				res[i][f] = (res[i][f] + x[i][j] * 1ll * y[j][f]) % p;
	return res;
}

vector<vector<int>> qpowA(long long k)
{
	if (k == 1) return a;
	if (k % 2) return mult(qpowA(k - 1), a);
	vector<vector<int>> res = qpowA(k / 2);
	return mult(res, res);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, q; long long m; cin >> n >> m >> q;
	map<int, vector<long long>> obst;
	for (int i = 0; i < q; ++i)
	{
		long long x, y; cin >> x >> y;
		obst[y - 1].push_back(x - 1);
	}

	vector<int> goodmask;
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		bool good = true;
		for (int i = 0; i < n;)
		{
			if (!get(mask, i))
			{
				++i;
				continue;
			}
			int cnt = 0;
			while (i < n && get(mask, i)) ++cnt, ++i;
			if (cnt % 2)
			{
				good = false;
				break;
			}
		}
		if (good)
			goodmask.push_back(mask);
	}
	int k = goodmask.size();
	a.resize(k, vector<int>(k));
	vector<int> cnt0(k);
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < n; ++j)
			if (!get(goodmask[i], j))
				++cnt0[i];
	for (int i = 0; i < k; ++i)
	{
		int d = 1 << cnt0[i];
		for (int j = 0; j < n - cnt0[i]; ++j)
			d = (d * 1ll * anti2) % p;
		for (int j = 0; j < k; ++j)
			if (!(goodmask[i] & goodmask[j]))
				a[i][j] = d;
	}

	vector<vector<int>> tek(k, vector<int>(1));
	tek[0][0] = (1 << n);
	long long l = 0;
	for (auto& i : obst)
	{
		long long d = i.first - l;
		if (d >= 1)
			tek = mult(qpowA(d), tek);
		l = i.first;
		for (int j = 0; j < k; ++j)
			for (auto& s : i.second)
			{
				if (get(goodmask[j], s))
					tek[j][0] = 0;
				else
					tek[j][0] = (tek[j][0] * 1ll * anti2) % p;
			}
		if (l + 1 < m)
		{
			++l;
			tek = mult(a, tek);
			for (int j = 0; j < k; ++j)
				for (auto& s : i.second)
					if (get(goodmask[j], s))
						tek[j][0] = 0;
		}
	}
	long long d = m - 1 - l;
	if (d >= 1)
		tek = mult(qpowA(d), tek);
	l = d;

	int res = 0;
	for (auto& i : tek)
		res = (res + i[0]) % p;
	cout << res << '\n';

	return 0;

}