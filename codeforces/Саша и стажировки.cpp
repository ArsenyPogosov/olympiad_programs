//source: https://codeforces.com/gym/102330/problem/G
//status: solved

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

int p = 1000000000 + 7;

int main()
{
	string n;
	int k;
	cin >> n >> k;

	vector<char> prime(1000000);
	for (int i = 2; i < 1000000; ++i) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1005; ++i)
		if (prime[i] == 1)
			for (int j = i * i; j < 1000000; j += i)
				prime[j] = 0;

	vector<int> dp(n.size() + 1);
	dp[0] = 1;
	for (int i = 0; i < n.size(); ++i)
	{
		int tkn = 0;
		for (int j = 1; j <= k && j <= n.size() - i; ++j)
		{
			tkn = tkn * 10 + (n[i + j - 1] - '0');
			if (tkn == 0) break;
			if (prime[tkn] == 1)
				dp[i + j] = (dp[i + j] + dp[i]) % p;
		}
	}
	cout << dp[n.size()];

	return 0;
}