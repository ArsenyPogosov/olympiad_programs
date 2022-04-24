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

const long long INF = 1000000000;

long long n, m;
vector<vector<long long>> mass, pref;
vector<vector<vector<vector<long long>>>> dp;

long long gpref(long long l, long long r)
{
	return (l >= 0 && r >= 0 ? pref[l][r] : 0);
}

long long sum(long long l1, long long r1, long long l2, long long r2)
{
	return gpref(l2, r2) - gpref(l1 - 1, r2) - gpref(l2, r1 - 1) + gpref(l1 - 1, r1 - 1);
}

long long res(long long l1, long long r1, long long l2, long long r2)
{
	if (dp[l1][r1][l2][r2] != -1) return dp[l1][r1][l2][r2];

	if (l1 == l2 && r1 == r2) return 0;

	dp[l1][r1][l2][r2] = INF;
	for (long long i = l1; i < l2; ++i)
		dp[l1][r1][l2][r2] = min(dp[l1][r1][l2][r2], res(l1, r1, i, r2) + res(i + 1, r1, l2, r2));
	for (long long i = r1; i < r2; ++i)
		dp[l1][r1][l2][r2] = min(dp[l1][r1][l2][r2], res(l1, r1, l2, i) + res(l1, i + 1, l2, r2));
	dp[l1][r1][l2][r2] += sum(l1, r1, l2, r2);
	return dp[l1][r1][l2][r2];
}

int main()
{
	cin >> n >> m;
	mass.resize(n, vector<long long>(m));
	for (auto& i : mass) for (auto& j : i) cin >> j;
	pref.resize(n, vector<long long>(m));
	partial_sum(mass[0].begin(), mass[0].end(), pref[0].begin());
	for (long long i = 1; i < n; ++i)
	{
		pref[i][0] = pref[i - 1][0] + mass[i][0];
		for (long long j = 1; j < m; ++j) pref[i][j] = mass[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
	}
	dp.resize(n, vector<vector<vector<long long>>>(m, vector<vector<long long>>(n, vector<long long>(m, -1))));
	cout << res(0, 0, n - 1, m - 1);

	return 0;
}