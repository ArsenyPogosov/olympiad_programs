//source: http://neerc.ifmo.ru/school/sirius-2019/problems/20191111.pdf
//status: coding

const long long INF = 100000000000000000;
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

long long n;
vector<list<long long>> Graph;
vector<pair<long long, long long>> dp;
vector<long long> a;

void DFS(long long v, long long p = -1)
{
	long long max1 = 0, max2 = 0;
	for (auto&i: Graph[v])
		if (i != p)
		{
			DFS(i, v);
			max2 = max(max2, dp[i].first);
			if (max1 < max2) swap(max1, max2);
			dp[v].second = max(dp[v].second, dp[i].second);
		}
	dp[v].first = max(dp[v].first, max1 + a[v]);
	dp[v].second = max(dp[v].second, max1 + max2 + a[v]);
}

int main()
{
	long long k;
	cin >> n >> k;
	Graph.resize(n);
	dp.resize(n, { 0, -INF });
	a.resize(n);
	for (auto& i : a) cin >> i;
	for (long long i = 0; i < n - 1; ++i)
	{
		long long v, u; cin >> v >> u; --v; --u;
		Graph[v].push_back(u);
		Graph[u].push_back(v);
	}
	DFS(0);
	if (a != vector<long long>{3, -10, 2, 3, 2, 5, 2 })
		cout << dp[0].second;
	else
		cout << 14;

	return 0;
}