#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, d;
vector<vector<int>> graph;

vector<int> D, res;

pair<int, int> DFS(int v, int p = -1)
{
	int sum = 1;
	vector<int> mind{ v };
	for (auto&i: graph[v])
		if (i != p)
		{
			auto tres = DFS(i, v);
			sum += tres.first;
			mind.push_back(tres.second);
			++D[tres.second];
		}
	sort(mind.begin(), mind.end(), [&](int a, int b) { return D[a] > D[b]; });
	while (mind.size() > 1)
	{
		if (D[mind[mind.size() - 1]] + D[mind[mind.size() - 2]] < d)
			mind.pop_back(), --sum;
		else
			break;
	}
	for (int i = 0; i < mind.size() - (p != -1); ++i)
		res.push_back(mind[i]);
	return { sum, mind[mind.size() - 1] };
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> d; graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	D.resize(n);
	cout << DFS(0).first << '\n';
	for (auto& i : res) cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}