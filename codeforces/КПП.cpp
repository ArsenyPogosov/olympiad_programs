//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260097
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("condense2.in");
ofstream fout("condense2.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<list<long long>> Graph, RGraph;
vector<long long> fire, tout, SCC;
long long t = 0;

void TSDFS(long long v)
{
	++t;
	fire[v] = 1;
	for (auto& i : Graph[v])
		if (!fire[i])
			TSDFS(i);
	tout[v] = t++;
}

void SCDFS(long long v, long long c)
{
	SCC[v] = c;
	for (auto& i : RGraph[v])
		if (SCC[i] == -1)
			SCDFS(i, c);
}

int main()
{
	long long n; cin >> n;
	vector<long long> cost(n);
	for (auto& i : cost) cin >> i;
	long long m; cin >> m;
	Graph.resize(n);
	RGraph.resize(n);
	fire.resize(n);
	tout.resize(n, -1);
	SCC.resize(n, -1);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b; cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		RGraph[b].push_back(a);
	}

	for (long long i = 0; i < n; ++i)
		if (tout[i] == -1)
			TSDFS(i);
	vector<long long> ts(n);
	iota(ts.begin(), ts.end(), 0);
	sort(ts.begin(), ts.end(), [&](long long a, long long b) {
		return tout[a] > tout[b];
		});

	long long c = 0;
	for (auto& i : ts)
		if (SCC[i] == -1)
			SCDFS(i, c++);

	vector<pair<long long, long long>> minn(c, { 1000000001, -1 });
	for (long long i = 0; i < n; ++i)
	{
		if (minn[SCC[i]].first == cost[i]) ++minn[SCC[i]].second;
		if (minn[SCC[i]].first > cost[i])
		{
			minn[SCC[i]] = { cost[i], 1 };
		}
	}

	long long sum = 0, count = 1;
	for (long long i = 0; i < c; ++i)
	{
			sum += minn[i].first;
			count = count * minn[i].second % 1000000007;
	}
	cout << sum << ' ' << count;

	return 0;
}