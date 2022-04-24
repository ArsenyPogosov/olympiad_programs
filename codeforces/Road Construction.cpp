#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> par, d;

int get(int a)
{
	if (par[a] == a) return a;
	return par[a] = get(par[a]);
}

int unite(int a, int b)
{
	a = get(a); b = get(b);
	if (a == b) return -1;
	if (d[a] > d[b]) swap(a, b);
	par[a] = b;
	d[b] += d[a];
	return d[b];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; par.resize(n); iota(par.begin(), par.end(), 0); d.resize(n, 1);
	int mx = 1, cnt = n;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		int res = unite(a - 1, b - 1);
		if (res != -1)
		{
			--cnt;
			mx = max(mx, res);
		}
		cout << cnt << ' ' << mx << '\n';
	}

	return 0;
}