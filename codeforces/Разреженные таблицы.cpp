//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258672/problems
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

long long n, m;
vector<long long> LOG2(100000 + 1), mass;
vector<vector<long long>> ST;

void build()
{
	long long teki = 0, tekp = 1;
	for (long long i = 1; i <= n; ++i)
	{
		if (tekp * 2 <= i) { tekp *= 2; ++teki; }
		LOG2[i] = teki;
	}

	m = LOG2[n] + 1;
	ST.resize(m, vector<long long>(n));
	copy(mass.begin(), mass.end(), ST[0].begin());
	for (long long i = 1; i < m; ++i)
		for (long long j = 0; j < n; ++j)
			ST[i][j] = min(ST[i - 1][j], ST[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

long long Min(long long l, long long r)
{
	if (l > r) swap(l, r);
	long long mi = LOG2[r - l + 1];
	return min(ST[mi][l], ST[mi][r - (1 << mi) + 1]);
}

int main()
{
	long long k; cin >> n >> k;
	mass.resize(n);
	long long a0; cin >> a0; mass[0] = a0;
	for (long long i = 1; i < n; ++i) mass[i] = (23 * mass[i - 1] + 21563) % 16714589;
	build();
	long long ui, vi, ansi;
	cin >> ui >> vi; ansi = Min(ui - 1, vi - 1);
	for (long long i = 2; i <= k; ++i)
	{
		ui = ((17 * ui + 751 + ansi + 2 * i - 2) % n) + 1;
		vi = ((13 * vi + 593 + ansi + 5 * i - 5) % n) + 1;
		ansi = Min(ui - 1, vi - 1);
	}
	cout << ui << ' ' << vi << ' ' << ansi << '\n';

	return 0;
}