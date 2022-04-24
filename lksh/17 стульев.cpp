#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 100000;

int mpop(int mask, int i)
{
	return mask ^ (1 << i);
}

int main()
{
	int n;
	cin >> n;
	int pown = (1 << n);
	vector<vector<int>> w(n, vector<int>(n));
	for (auto&i : w)
		for (auto&j : i)
		{
			cin >> j;
			if (j == 0)
				j = INF;
		}
	vector<vector<int>> dp(1 << n, vector<int>(n, INF));
	vector<vector<pair<int, int>>> p(1 << n, vector<pair<int, int>>(n, { -1, -1 }));
	dp[1][0] = 0;
	for (int mask = 1; mask < pown; ++mask)
		for (int i = 1; i < n; ++i)
			if (mask & (1 << i))
				for (int j = 0; j < n; ++j)
					if (i != j && (mask & (1 << j)))
					{
						int nmask = mpop(mask, i);
						if (dp[nmask][j] + w[j][i] < dp[mask][i])
						{
							dp[mask][i] = dp[nmask][j] + w[j][i];
							p[mask][i] = { nmask, j };
						}
					}
	int minn = 0;
	for (int i = 1; i < n; ++i)
		if (dp[pown - 1][minn] > dp[pown - 1][i])
			minn = i;
	if (dp[pown - 1][minn] >= INF)
	{
		cout << -1;
		return 0;
	}
	cout << dp[pown - 1][minn] << '\n';
	pair<int, int> cur = { pown - 1, minn };
	vector<int> res;
	res.reserve(n);
	while (cur != pair<int, int>{-1, -1})
	{
		res.push_back(cur.second);
		cur = p[cur.first][cur.second];
	}
	reverse(res.begin(), res.end());
	for (auto&i : res)
		cout << i + 1 << ' ';

	return 0;
}