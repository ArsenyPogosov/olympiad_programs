#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m, p;
vector<int> a(n), b(m);
vector<vector<int>> grn, grm, resn, resm;

int Resn(int v, int x);
int Resm(int v, int x);

int Resn(int v, int x)
{
	if (x >= grn[v].size())
		return a[v];
	if (resn[v][x] != -1) return resn[v][x];
	resn[v][x] = a[v];
	int u = grn[v][x], 
		y = upper_bound(grm[u].begin(), grm[u].end(), v) - grm[u].begin();
	resn[v][x] += Resm(u, y);
	resn[v][x] = max(resn[v][x], Resn(v, x + 1));
	return resn[v][x];
}

int Resm(int v, int x)
{
	if (x >= grm[v].size())
		return b[v];
	if (resm[v][x] != -1) return resm[v][x];
	resm[v][x] = b[v];
	int u = grm[v][x],
		y = upper_bound(grn[u].begin(), grn[u].end(), v) - grn[u].begin();
	resm[v][x] += Resn(u, y);
	resm[v][x] = max(resm[v][x], Resm(v, x + 1));
	return resm[v][x];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	a.resize(n); b.resize(m);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	grn.resize(n); grm.resize(m); resn.resize(n); resm.resize(m);
	for (int i = 0; i < p; ++i)
	{
		int u, v; cin >> u >> v; --u; --v;
		grn[u].push_back(v);
		grm[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		resn[i].resize(grn[i].size(), -1);
	for (int i = 0; i < m; ++i)
		resm[i].resize(grm[i].size(), -1);
	for (auto& i : grn) sort(i.begin(), i.end());
	for (auto& i : grm) sort(i.begin(), i.end());
	int res = -1;
	for (int i = 0; i < n; ++i)
		res = max(res, Resn(i, 0));
	for (int i = 0; i < m; ++i)
		res = max(res, Resm(i, 0));
	cout << res << '\n';

	return 0;
}