#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	vector<vector<pair<int, int>>> per(n + 1, vector<pair<int, int>>(m + 1, { -1, -1 }));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (a[i] == b[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				per[i + 1][j + 1] = { i, j };
			}
			else
			{
				if (dp[i + 1][j] > dp[i][j + 1])
				{
					dp[i + 1][j + 1] = dp[i + 1][j];
					per[i + 1][j + 1] = { i + 1, j };
				}
				else
				{
					dp[i + 1][j + 1] = dp[i][j + 1];
					per[i + 1][j + 1] = { i, j + 1 };
				}
			}
		}
	string res = "";
	pair<int, int> cur = { n, m };
	while (cur.first*cur.second != 0)
	{
		if (a[cur.first - 1] == b[cur.second - 1])
			res += a[cur.first - 1];
		cur = per[cur.first][cur.second];
	}
	reverse(res.begin(), res.end());
	cout << res;

	return 0;
}