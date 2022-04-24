//source: file:///C:/Users/arsen/Downloads/13.11.19.%201%20%D0%B3%D1%80%D1%83%D0%BF%D0%BF%D0%B0.%20%D0%94%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D0%BA%D0%B0%20%D0%BF%D0%BE%20%D0%BF%D0%BE%D0%B4%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%B0%D0%BC%20%D0%B8%20%D0%BF%D1%80%D0%BE%D1%84%D0%B8%D0%BB%D1%8E.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("b3.in");
ofstream fout("b3.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	long long m, n; cin >> m >> n;
	vector<long long> dp(n + 1);
	dp[0] = 1;
	for (long long i = 1; i <= n; ++i)
		dp[i] = dp[i - 1] + (i >= m ? dp[i - m] : 0);
	cout << dp[n];

	return 0;
}