//source: 
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
	long long n, t, d;
	cin >> n >> t >> d;
	vector<long long> v(n);
	for (auto& i : v) cin >> i;
	vector<long long> dp(n);
	dp[0] = t * v[0];
	for (long long i = 1; i < n; ++i)
		dp[i] = dp[i - 1] + v[i] * t;
	double maxx = 100000000000000000;
	for (long long i = 0; i < n; ++i)
		if (d >= ((i != 0 ? dp[i - 1] : 0) + dp[i]) && v[i] != 0)
			maxx = min(maxx, double(d - ((i != 0 ? dp[i - 1] : 0) + dp[i])) / v[i] + (i * 2 + 1) * t);
	maxx = min(maxx, double(d) / v[0]);
	cout << fixed << setprecision(16) << maxx;

	return 0;
}