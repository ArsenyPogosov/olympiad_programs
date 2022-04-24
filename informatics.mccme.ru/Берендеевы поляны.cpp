#include <iostream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<pair<int, bool>>> suspGraph;
list<int> ans;

void solve(int v)
{
	ans.push_back(v + 1);
	for (auto&i : suspGraph[v])
	{
		if (i.second)
		{
			solve(i.first);
			ans.push_back(v + 1);
		}
		else
		{
			ans.push_back(i.first + 1);
			ans.push_back(v + 1);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<list<int>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	suspGraph.resize(n);
	vector<int> fire(n, -1);
	queue<int> Q;
	Q.push(0); fire[0] = 0;
	while (!Q.empty())
	{
		auto it = graph[Q.front()].begin();
		while(it != graph[Q.front()].end())
		{
			if (*it == fire[Q.front()])
			{
				it = graph[Q.front()].erase(it); 
				continue;
			}
			if (fire[*it] == -1)
			{
				suspGraph[Q.front()].push_back({ *it, true });
				Q.push(*it);
				fire[*it] = Q.front();
				it = graph[Q.front()].erase(it);
				continue;
			}
			++it;
		}

		Q.pop();
	}
	for (int i = 0; i < n; ++i)
		for (auto&j : graph[i])
			if (i < j)
				suspGraph[i].push_back({ j, false });
	solve(0);
	cout << ans.size() - 1 << '\n';
	for (auto&i : ans)
		cout << i << '\n';

	return 0;
}