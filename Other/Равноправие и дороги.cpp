#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<long long> dsu, r;

long long get(long long x)
{
	return (dsu[x] == -1 ? x : dsu[x] = get(dsu[x]));
}

bool con(long long x, long long y)
{
	return get(x) == get(y);
}

bool unite(long long x, long long y)
{
	x = get(x); y = get(y);
	if (x == y) return false;

	if (r[x] > r[y]) swap(x, y);
	dsu[x] = y;
	if (r[x] == r[y]) ++r[y];

	return true;
}

void buildDSU(long long n)
{
	dsu.assign(n, -1); r.assign(n, 0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, q; cin >> n >> m >> q;

	vector<pair<int, int>> a, b;
	for (int i = 0; i < m; ++i)
	{
		int v, u, t; cin >> v >> u >> t; --v; --u;
		if (t == 0)
			a.emplace_back(v, u);
		else
			b.emplace_back(v, u);
	}

	int mn = n - 1;
	buildDSU(n);
	for (auto& i : b)
		if (unite(i.first, i.second))
			--mn;

	int mx = 0;
	buildDSU(n);
	for (auto& i : a)
		if (unite(i.first, i.second))
			++mx;
	int k = mx;
	for (auto& i : b)
		if (unite(i.first, i.second))
			++k;

	if (k != n - 1)
		mn = mx = -1;

	while(q--)
	{
		int h; cin >> h;
		if (mn <= h && h <= mx)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}