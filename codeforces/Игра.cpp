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

int n;
vector<int> mass, pref;
vector<vector<int>> dp;

int sum(int l, int r)
{
	return pref[r] - (l > 0 ? pref[l - 1] : 0);
}

int res(int l, int r)
{
	if (dp[l][r] != -1) return dp[l][r];

	if (l == r) return mass[l];
	return dp[l][r] = max(sum(l, r - 1) - res(l, r - 1) + mass[r],
		sum(l + 1, r) - res(l + 1, r) + mass[l]);
}

int main()
{
	cin >> n;
	mass.resize(n);
	pref.resize(n);
	for (auto& i : mass) cin >> i;
	partial_sum(mass.begin(), mass.end(), pref.begin());
	dp.resize(n, vector<int>(n, -1));
	cout << res(0, n - 1);

	return 0;
}