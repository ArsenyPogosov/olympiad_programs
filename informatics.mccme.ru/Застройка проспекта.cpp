#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

long long p = 1000000007;

int main()
{
	long long n = 100000;
	cin >> n;
	vector<vector<long long>> dp(n + 3, vector<long long>(4));
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
	for (long long i = 4; i <= n; ++i)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%p;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%p;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%p;
	}
	cout << (dp[n][1] + dp[n][2] + dp[n][3])%p;

	return 0;
}