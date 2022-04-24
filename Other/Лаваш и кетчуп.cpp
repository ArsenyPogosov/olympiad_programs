#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m, d, q;

vector<int> dsu, srank;

int get(int x)
{
	if (dsu[x] == -1) return x;
	return dsu[x] = get(dsu[x]);
}

bool unite(int a, int b)
{
	a = get(a); b = get(b);
	if (a == b) return false;
	if (srank[a] < srank[b]) swap(a, b);
	if (srank[a] == srank[b]) ++srank[a];
	dsu[b] = a;
	return true;
}

vector<vector<pair<int, int>>> graph;

vector<int> color;

multiset<int> res;
vector<map<int, multiset<int>>> downres;

vector<int> par, parc;

void DFS(int v, int p = -1)
{
	par[v] = p;
	for (auto& i : graph[v])
		if (i.first != p)
		{
			downres[v][color[i.first]].insert(i.second);
			DFS(i.first, v);
		}
		else
			parc[v] = i.second;
	for (auto& i : downres[v])
		if (color[v] != i.first)
			res.insert(*i.second.begin());
}

void change(int v, int c)
{
	if (color[v] == c) return;

	if (par[v] != -1)
	{
		if (color[par[v]] != color[v])
			res.erase(res.find(*downres[par[v]][color[v]].begin()));
		downres[par[v]][color[v]].erase(downres[par[v]][color[v]].find(parc[v]));
		if (downres[par[v]][color[v]].empty()) 
			downres[par[v]].erase(color[v]);
		else
			if (color[par[v]] != color[v])
				res.insert(*downres[par[v]][color[v]].begin());

		if (color[par[v]] != c && (downres[par[v]].find(c) != downres[par[v]].end()))
			res.erase(res.find(*downres[par[v]][c].begin()));
		downres[par[v]][c].insert(parc[v]);
		if (color[par[v]] != c)
			res.insert(*downres[par[v]][c].begin());
	}
	if (downres[v].find(color[v]) != downres[v].end())
		res.insert(*downres[v][color[v]].begin());
	if (downres[v].find(c) != downres[v].end())
		res.erase(res.find(*downres[v][c].begin()));
	color[v] = c;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> d >> q;
	dsu.resize(n, -1); srank.resize(n);
	vector<pair<int, pair<int, int>>> edge(m);
	for (auto&i: edge)
	{
		cin >> i.second.first >> i.second.second >> i.first;
		--i.second.first; --i.second.second;
	}
	sort(edge.begin(), edge.end());
	graph.resize(n);
	for (auto& i : edge)
	{
		int u = i.second.first, v = i.second.second, c = i.first;
		if (unite(u, v))
		{
			graph[u].emplace_back(v, c);
			graph[v].emplace_back(u, c);
		}
	}
	color.resize(n);
	for (auto& i : color) cin >> i;
	par.resize(n); parc.resize(n);
	downres.resize(n);
	DFS(0);
	while (q--)
	{
		int a, b; cin >> a >> b; change(a - 1, b);
		cout << *res.begin() << '\n';
	}

	return 0;
}