#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 1000000000;

int main()
{
	int w, h, n;
	cin >> w >> h >> n;
	vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0));
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		dp[a][b] = 1;
	}
	for (int i = 1; i <= w; ++i)
		for (int j = 1; j <= h; ++j)
		{
			for (int k = 1; k < i; ++k)
				dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
			for (int k = 1; k < j; ++k)
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
		}
	cout << dp[w][h];

	return 0;
}