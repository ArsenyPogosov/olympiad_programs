#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> used(n, -1); used[0] = 0;
	queue<int> Q; Q.push(0);
	while (Q.size())
	{
		int v = Q.front(); Q.pop();
		for (auto&i: graph[v])
			if (used[i] == -1)
			{
				Q.push(i);
				used[i] = v;
			}
	}
	
	used[0] = -1;
	if (used[n - 1] == -1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	} 
	vector<int> res;
	int it = n - 1;
	while (it != -1)
	{
		res.push_back(it);
		it = used[it];
	}
	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto& i : res)
		cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}