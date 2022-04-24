#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph, rgraph;

vector<int> order, used;
void oDFS(int v)
{
	if (used[v]) return; used[v] = true;
	for (auto& i : graph[v])
		oDFS(i);
	order.push_back(v);
}

int c = 0;
vector<int> color;
void cDFS(int v)
{
	if (color[v] != -1) return;
	color[v] = c;
	for (auto& i : rgraph[v])
		cDFS(i);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> m >> n;
	graph.resize(n * 2); rgraph.resize(n * 2);
	order.reserve(n * 2); used.resize(n * 2);
	color.resize(n * 2, -1);
	for (int i = 0; i < m; ++i)
	{
		char h1, h2;
		int v1, v2;
		cin >> h1 >> v1 >> h2 >> v2; --v1; --v2;
		v1 = v1 * 2 + (h1 == '-');
		v2 = v2 * 2 + (h2 == '-');
		graph[v1 ^ 1].push_back(v2);
		graph[v2 ^ 1].push_back(v1);
		rgraph[v1].push_back(v2 ^ 1);
		rgraph[v2].push_back(v1 ^ 1);
	}

	for (int i = 0; i < n * 2; ++i)
		oDFS(i);
	reverse(order.begin(), order.end());

	for (auto& i : order)
		if (color[i] == -1)
			cDFS(i), ++c;

	vector<char> res(n);
	for (int i = 0; i < n; ++i)
	{
		if (color[i * 2] == color[i * 2 + 1])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		res[i] = (color[i * 2] > color[i * 2 + 1] ? '+' : '-');
	}
	for (auto& i : res) cout << i << ' '; cout << '\n';

	return 0;
}