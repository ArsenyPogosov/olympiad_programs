//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259655/problem/I
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("salesman.in");
ofstream fout("salesman.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

const int INF = 2000000000;

int get(int mask, int i)
{
	return (mask >> i) & 1;
}

int main()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(n, -1));
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a][b] = c; graph[b][a] = c;
	}
	vector<vector<int>> dp((1 << n), vector<int>(n, INF));
	for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
	for (int mask = 1; mask < (1 << n) - 1; ++mask)
		for (int v = 0; v < n; ++v)
			if (get(mask, v))
				for (int u = 0; u < n; ++u)
					if ((!get(mask, u))&&graph[v][u] != -1)
					{
						dp[mask | (1 << u)][u] = min(dp[mask | (1 << u)][u], dp[mask][v] + graph[v][u]);
					}
	int minn = INF;
	for (auto& i : dp[(1 << n) - 1]) minn = min(minn, i);
	cout << (minn < INF ? minn : -1);

	return 0;
}