//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259655/problem/H
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("perm.in");
ofstream fout("perm.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

long long get(long long mask, long long i)
{
	return (mask >> i) & 1;
}

long long GCD(long long a, long long b)
{
	return (b == 0 ? a : GCD(b, a % b));
}

long long f1(long long mask)
{
	if (!mask) return -1;
	long long i = -1, h = mask ^ (mask - 1);
	while (h > 0) { ++i; h /= 2; }
	return i;
}

int main()
{
	long long n, m, k; cin >> n >> m >> k;
	vector<long long> mass(n);
	for (auto& i : mass) cin >> i;
	sort(mass.begin(), mass.end());
	vector<vector<long long>> graph(n, vector<long long>(n, 0));
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < n; ++j)
			graph[i][j] = (GCD(mass[i], mass[j]) >= k);
	vector<vector<long long>> dp(1 << n, vector<long long>(n));
	for (long long i = 0; i < n; ++i) dp[1 << i][i] = 1;
	for (long long mask = 1; mask < (1 << n); ++mask)
		for (long long i = 0; i < n; ++i)
			if (get(mask, i))
				for (long long j = 0; j < n; ++j)
					if (get(mask ^ (1 << i), j) && graph[i][j])
						dp[mask][i] += dp[mask ^ (1 << i)][j];
	long long tm = (1 << n) - 1, ti = -1;
	vector<long long> ans; ans.reserve(n);
	for (long long i = 0; i < n; ++i)
		if (get(tm, i) && ((ti == -1)||(graph[ti][i])))
		{
			if (m > dp[tm][i])
			{
				m -= dp[tm][i];
				continue;
			}
			else
			{
				ans.push_back(i);
				tm ^= (1 << i);
				ti = i;
				i = -1;
			}
		}

	if (tm != 0) { cout << -1; return 0; }
	for (auto& i : ans) cout << mass[i] << ' ';

	return 0;
}