//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259151/problems
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

long long n;
vector<list<long long>> Graph;
vector<long long> q;
vector<vector<long long>> dp;

void DFS(long long v)
{
	dp[v][0] = 0;
	for (auto& i : Graph[v])
	{
		DFS(i);
		dp[v][0] += dp[i][1];
	}
	dp[v][1] = q[v];
	for (auto& i : Graph[v])
	{
		dp[v][1] += dp[i][0];
	}
	dp[v][1] = max(dp[v][1], dp[v][0]);
}

int main()
{
	cin >> n;
	Graph.resize(n), q.resize(n); dp.resize(n, vector<long long>(2));
	long long root = -1;
	for (long long i = 0; i < n; ++i)
	{
		long long pi, qi; cin >> pi >> qi;
		q[i] = qi;
		if (pi != 0)
			Graph[pi - 1].push_back(i);
		else
			root = i;
	}
	DFS(root);
	cout << dp[root][1];

	return 0;
}