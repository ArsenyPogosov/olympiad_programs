#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph, rgraph;

vector<int> used, tsort;
void dfstsort(int v)
{
	if (used[v]) return;
	used[v] = true;

	for (auto& i : graph[v])
		dfstsort(i);
	tsort.push_back(v);
}

int c;
vector<int> colour;
void dfscolour(int v)
{
	if (colour[v] != -1) return;
	colour[v] = c;

	for (auto& i : rgraph[v])
		dfscolour(i);
}

vector<set<int>> cgraph;
vector<bitset<5 * 10000>> anc;

void dfsanc(int v)
{
	if (anc[v][v]) return;

	anc[v][v] = 1;
	for (auto& i : cgraph[v])
	{
		dfsanc(i);
		anc[v] |= anc[i];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q; cin >> n >> m >> q;
	graph.resize(n); rgraph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		rgraph[b - 1].push_back(a - 1);
	}

	used.resize(n);
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfstsort(i);

	c = 0;
	colour.resize(n, -1);
	for (int i = n - 1; i >= 0; --i)
		if (colour[tsort[i]] == -1)
			dfscolour(tsort[i]), ++c;

	cgraph.resize(c);
	for (int i = 0; i < n; ++i)
		for (auto& j : graph[i])
			if (colour[i] != colour[j])
				cgraph[colour[i]].insert(colour[j]);

	anc.resize(c);
	for (int i = 0; i < c; ++i) dfsanc(i);

	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << (anc[colour[a - 1]][colour[b - 1]] ? "YES" : "NO") << '\n';
	}

	return 0;
}