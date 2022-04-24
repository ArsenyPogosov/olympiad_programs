//source: https://codeforces.com/contest/1243/problem/D
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n, m; cin >> n >> m;
	vector<set<int>> Graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		Graph[min(a, b)].insert(max(a, b));
	}
	int count = 0;
	set<int> unused;
	for (int i = 0; i < n; ++i) unused.insert(i);
	while (unused.size())
	{
		++count;
		int v = *unused.begin(); unused.erase(unused.begin());
		int bef = v; Graph[v].insert(n);
		while( Graph[v].size())
		{
			for (auto it = unused.upper_bound(bef); (bef + 1 <= *Graph[v].begin()) && (it != unused.lower_bound(*Graph[v].begin()));)
			{
				int u = *it; it = unused.erase(it);
				int bf = u; Graph[u].insert(n);
				for (auto& j : Graph[u])
				{
					for (auto itt = Graph[v].upper_bound(bf); (bf + 1 < j) && (itt != Graph[v].lower_bound(j));)
						itt = Graph[v].erase(itt);
					bf = j;
				}

			}
			bef = *Graph[v].begin(); Graph[v].erase(Graph[v].begin());
		}
	}
	cout << count - 1;

	return 0;
}