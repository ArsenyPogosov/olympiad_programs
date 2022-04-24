#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long gethash(vector<vector<int>>& graph, int v, int p = -1)
{
	vector<long long> tohash; tohash.reserve(graph[v].size() - (p != -1));
	for (auto& i : graph[v])
		if (i != p)
			tohash.push_back(gethash(graph, i, v));
	string res = "1";
	sort(tohash.begin(), tohash.end());
	for (auto& i : tohash)
		res += to_string(i);
	return hash<string>()(res);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<vector<int>> graph1(n), graph2(n);
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph1[a].push_back(b);
			graph1[b].push_back(a);
		}
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph2[a].push_back(b);
			graph2[b].push_back(a);
		}
		cout << (gethash(graph1, 0) == gethash(graph2, 0) ? "YES" : "NO") << '\n';
	}

	return 0;
}