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
vector<long long> dp;

void DFS(long long v, long long p = -1)
{
	dp[v] = 1;
	for (auto& i : Graph[v])
		if (i != p)
		{
			DFS(i, v);
			dp[v] += dp[i];
		}
}

int main()
{
	cin >> n;
	Graph.resize(n); dp.resize(n);
	vector<pair<long long, long long>> brunch; brunch.reserve(n - 1);
	for (long long i = 0; i < n - 1; ++i)
	{
		long long a, b; cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
		brunch.push_back({ a, b });
	}
	DFS(0);
	for (auto& i : brunch)
	{
		long long s = min(dp[i.first], dp[i.second]);
		cout << s * (n - s) << '\n';
	}

	return 0;
}