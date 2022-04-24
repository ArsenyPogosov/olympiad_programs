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
	++d[b];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; par.resize(n); iota(par.begin(), par.end(), 0); d.resize(n);
	multimap<int, pair<int, int>> br;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		br.insert({ c, { a - 1, b - 1} });
	}
	long long res = 0, k = 0;
	for (auto& i : br)
		if (unite(i.second.first, i.second.second) != -1)
			res += i.first, ++k;
	if (k == n - 1)
		cout << res << '\n';
	else
		cout << "IMPOSSIBLE\n";

	return 0;
}