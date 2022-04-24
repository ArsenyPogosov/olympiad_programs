#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> mass(n);
	for (auto&i : mass)
		cin >> i;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int r = 0; r < n; ++r)
		for (int l = r; l >= 0; l -= 2)
		{
			if ((r - l + 1) % 2 == 1)
			{
				++l;
				continue;
			}
			if (r - l + 1 == 2)
			{
				dp[l][r] = max(mass[l], mass[r]);
				continue;
			}
			int x = 0, y = 0, z = 0;
			int a = mass[l] + min(dp[l + 2][r], dp[l + 1][r - 1]);
			int b = mass[r] + min(dp[l + 1][r - 1], dp[l][r - 2]);
			dp[l][r] = max(a, b);
		}
	cout << dp[0][n - 1];

	return 0;
}