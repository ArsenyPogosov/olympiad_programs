#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> par;
vector<int> rnk;

void init(int n)
{
	par.resize(n); iota(par.begin(), par.end(), 0);
	rnk.resize(n);
}

int get(int a)
{
	if (par[a] == a) return a;
	return par[a] = get(par[a]);
}

bool unite(int a, int b)
{
	a = get(a); b = get(b);
	if (a == b) return false;
	if (rnk[a] > rnk[b]) swap(a, b);
	par[a] = b;
	rnk[b] = max(rnk[b], rnk[a] + 1);
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k; init(n);
	set<pair<int, int>> edge;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; if (a > b) swap(a, b);
		edge.emplace(a - 1, b - 1);
	}
	vector<pair<int, int>> add;
	for (int i = 0; i < k; ++i)
	{
		int a, b; cin >> a >> b; if (a > b) swap(a, b);
		add.emplace_back(a - 1, b - 1);
		edge.erase(add[i]);
	}
	int count = n;
	for (auto& i : edge) count -= unite(i.first, i.second);
	vector<int> res(k);
	for (int i = k - 1; i >= 0; --i)
	{
		res[i] = count;
		count -= unite(add[i].first, add[i].second);
	}
	for (auto& i : res) cout << i << ' ';
	cout << '\n';

	return 0;
}