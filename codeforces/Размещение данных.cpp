//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("data.in");
ofstream fout("data.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

const long long p = 1e9 + 7;

int n, m;
vector<list<int>> Graph;
vector<int> fup, used, d;
vector<pair<int, int>> bridge;

void DFS(int u, int p = -1)
{
	used[u] = true;
	d[u] = (p >= 0 ? d[p] + 1 : 0);
	fup[u] = d[u];

	for (auto&v: Graph[u])
		if (v != p)
		{
			if (used[v])
				fup[u] = min(fup[u], d[v]);
			else
			{
				DFS(v, u);
				fup[u] = min(fup[u], fup[v]);
				if (fup[v] > d[u])
					bridge.push_back({ u, v });
			}
		}
}

int CountDFS(int u, int c)
{
	used[u] = c;
	int count = 1;
	for (auto& v : Graph[u])
		if (used[v] == -1)
			if (!binary_search(bridge.begin(), bridge.end(), pair<int, int>({ u, v })))
				if (!binary_search(bridge.begin(), bridge.end(), pair<int, int>({ v, u })))
					count += CountDFS(v, c);
	
	return count;
}

int main()
{
	cin >> n >> m;
	Graph.resize(n);
	int u, v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		--u;
		--v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	fup.resize(n); d.resize(n), used.resize(n);
	DFS(0);
	sort(bridge.begin(), bridge.end());

	int c = 0;
	vector<int> count(n), cp(n);
	used.assign(n, -1);
	for (int i = 0; i < n; ++i)
		if (used[i] == -1)
		{
			count[c] = CountDFS(i, c);
			++c;
		}
	for (auto& i : bridge)
	{
		++cp[used[i.first]];
		++cp[used[i.second]];
	}
	int res = 0;
	long long vc = 1;
	for (int i = 0; i < c; ++i)
		if (cp[i] == 1)
		{
			++res;
			vc = (vc * (long long)(count[i])) % p;
		}
	if (res > 0)
		cout << res << ' ' << vc << '\n';
	else
		cout << 1 << ' ' << n % p << '\n';

	return 0;
}