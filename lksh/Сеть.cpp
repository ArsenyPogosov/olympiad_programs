#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int OldestBit(int n)
{
	if (n == 1)
		return 0;
	return OldestBit(n >> 1) + 1;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (auto&i : g)
		for (auto&j : i)
		{
			char h;
			cin >> h;
			if (h == 'Y')
				j = true;
		}
	vector<int> dp(1 << n, 0);
	for (int mask = 1; mask < (1 << n); ++mask)
	{
		int v = OldestBit(mask);
		dp[mask] = dp[mask ^ (1 << v)];
		for (int i = 0; i < n; ++i)
			if (i != v && (mask & (1 << i)) && g[v][i])
				dp[mask] = max(dp[mask], dp[mask ^ (1 << v) ^ (1 << i)] + 2);
	}
	cout << dp[(1 << n) - 1];

	return 0;
}