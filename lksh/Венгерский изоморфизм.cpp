#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, n, m, start = -1;
vector<vector<int>> graph;
vector<char> del;
vector<int> line;

void delbrunch(int a, int b)
{
	vector<int> nv;
	for (auto& i : graph[a])
		if (i != b)
			nv.push_back(i);
	graph[a] = nv;
	nv.clear();
	for (auto& i : graph[b])
		if (i != a)
			nv.push_back(i);
	graph[b] = nv;
}

bool trim()
{
	vector<int> nline;
	for (int i = 0; i < n; ++i)
	{
		bool add = false;
		for (auto&j: graph[line[i]])
			if (i == 0 || j != line[i - 1])
				if (i == n - 1 || j != line[i + 1])
					if (!del[j])
					{
						add = true;
						del[j] = true;
						nline.push_back(j);
						delbrunch(line[i], j);
						break;
					}
		if (!add) return false;
	}

	line = nline;
	int islast = (m == 1);
	if (graph[line[0]].size() != 2 - islast) return false;
	if (graph[line[n - 1]].size() != 2 - islast) return false;
	for (int i = 1; i < n - 1; ++i)
		if (graph[line[i]].size() != 3 - islast) return false;
	for (int i = 0; i < n - 1; ++i)
	{
		bool have = false;
		for (auto&j: graph[line[i]])
			if (j == line[i + 1])
			{
				have = true;
				break;
			}
		if (!have) return false;
	}

	--m;
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; N = n * m; graph.resize(N); del.resize(N);
	if (n < m) swap(n, m);
	for (int i = 0; i < n * m * 2 - n - m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> c(5);
	for (int i = 0; i < N; ++i)
	{
		if (graph[i].size() < 2 || graph[i].size() > 4)
		{
			cout << "No\n";
			return 0;
		}
		++c[graph[i].size()];
		if (graph[i].size() == 2) start = i;
	}
	if (c[2] != 4 || c[3] != (n - 2) * 2 + (m - 2) * 2)
	{
		cout << "No\n";
		return 0;
	}

	line.push_back(start);
	if (graph[graph[start][0]].size() > 3)
	{
		cout << "No\n";
		return 0;
	}
	line.push_back(graph[start][0]);
	if (graph[line[1]].size() == 2)
	{
		if (n != 2) swap(n, m);
		if (n != 2)
		{
			cout << "No\n";
			return 0;
		}
	}
	else
	{
		for (int i = 2; i < max(n, m); ++i)
		{
			bool add = false;
			for (auto& j : graph[line[i - 1]])
				if (graph[j].size() < 4 && j != line[i - 2])
				{
					add = true;
					line.push_back(j);
					del[j] = true;
					break;
				}
			if (!add)
			{
				cout << "No\n";
				return 0;
			}
			if (graph[line[i]].size() == 2)
			{
				if (n != i + 1) swap(n, m);
				if (n != i + 1)
				{
					cout << "No\n";
					return 0;
				}
				break;
			}
		}
	} --m;
	while(m) if (!trim())
	{
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";


	return 0;
}