//source: file:///C:/Users/arsen/Downloads/13.11.19.%201%20%D0%B3%D1%80%D1%83%D0%BF%D0%BF%D0%B0.%20%D0%94%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D0%BA%D0%B0%20%D0%BF%D0%BE%20%D0%BF%D0%BE%D0%B4%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%B0%D0%BC%20%D0%B8%20%D0%BF%D1%80%D0%BE%D1%84%D0%B8%D0%BB%D1%8E.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("network.in");
ofstream fout("network.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int get(int mask, int i)
{
	return (mask >> i) & 1;
}

int main()
{
	int n; cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	for (auto&i : graph)
		for (auto& j : i)
		{
			char h; cin >> h; j = (h == 'Y' ? 1 : 0);
		}
	vector<int> dp(1 << n, 0);
	for (int mask = 0; mask < (1 << n) - 1; ++mask)
	{
		int h = mask ^ (mask + 1), v = -1;
		while (h > 0) { ++v; h /= 2; }
		for (int j = 0; j < n; ++j)
			if ((!get(mask, j))&&graph[v][j])
			{
				dp[mask | (1 << v) | (1 << j)] = max(dp[mask | (1 << v) | (1 << j)], dp[mask] + 2);
			}
		for (int j = 0; j < n; ++j) if (get(mask, j)) dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask]);
	}
	cout << dp[(1 << n) - 1];

	return 0;
}