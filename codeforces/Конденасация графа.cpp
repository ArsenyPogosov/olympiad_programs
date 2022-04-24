//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260097
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("condense2.in");
ofstream fout("condense2.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<list<int>> Graph, RGraph;
vector<set<int>> CGraph;
vector<int> fire, tout, SCC;
int t = 0;

void TSDFS(int v)
{
	++t;
	fire[v] = 1;
	for (auto& i : Graph[v])
		if (!fire[i])
			TSDFS(i);
	tout[v] = t++;
}

void SCDFS(int v, int c)
{
	SCC[v] = c;
	for (auto& i : RGraph[v])
		if (SCC[i] == -1)
			SCDFS(i, c);
}

int main()
{
	int n, m; cin >> n >> m;
	Graph.resize(n);
	RGraph.resize(n);
	fire.resize(n);
	tout.resize(n, -1);
	SCC.resize(n, -1);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		RGraph[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
		if (tout[i] == -1)
			TSDFS(i);
	vector<int> ts(n);
	iota(ts.begin(), ts.end(), 0);
	sort(ts.begin(), ts.end(), [&](int a, int b) {
		return tout[a] > tout[b];
	});

	int c = 0;
	for (auto& i : ts)
		if (SCC[i] == -1)
			SCDFS(i, c++);

	CGraph.resize(c);
	for (int u = 0; u < n; ++u)
		for (auto& v : Graph[u])
			if (SCC[u] != SCC[v])
				CGraph[SCC[u]].insert(SCC[v]);

	int count = 0;
	for (auto& i : CGraph)
		count += i.size();
	cout << count;

	return 0;
}