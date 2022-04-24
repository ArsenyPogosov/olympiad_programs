#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;

int cnt;
vector<int> dsu, sz;
vector<char> ban;

void initDsu()
{
	dsu.resize(n);
	iota(dsu.begin(), dsu.end(), 0);
	sz.resize(n, 1);
	ban.resize(n, 0);
}

int get(int v)
{
	return dsu[v] = (dsu[v] != v ? get(dsu[v]) : v);
}

bool unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b)
	{
		if (!ban[a])
			cnt += sz[a];
		ban[a] = true;

		return false;
	}

	if (sz[a] < sz[b]) swap(a, b);
	if (ban[a])
		cnt -= sz[a];
	if (ban[b])
		cnt -= sz[b];

	dsu[b] = a;
	sz[a] += sz[b];
	ban[a] |= ban[b];

	if (ban[a])
		cnt += sz[a];

	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m, q; cin >> n >> m >> q;

	initDsu();

	cnt = 0;
	while (m--)
	{
		int x, y; cin >> x >> y; --x; --y;
		unite(x, y);
	}

	while (q--)
	{
		int h; cin >> h;
		int x, y;
		if (h <= 2)
		{
			cin >> x >> y; --x; --y;
			cout << (ban[get(x)] && ban[get(y)] ? "No" : "Yes") << '\n';
		}
		if (h == 2)
		{
			unite(x, y);
		}
		if (h == 3)
			cout << n * 1ll * (n - 1) - cnt * 1ll * (cnt - 1) << '\n';
	}

	return 0;
}