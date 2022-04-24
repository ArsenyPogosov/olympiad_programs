#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		if (b != 0)
			graph[a].push_back(b);
	}

	int path[1 << 20][20]; path[0][0] = 1;
	for (auto& i : graph[0])
		path[(1 << (i - 1))][i] = (path[1 << (i - 1)][i] + 1);
	for (int mask = 1; mask < (1 << (n - 1)); ++mask)
		for (int v = 1; v < n; ++v)
			if (path[mask][v] != 0)
				for (auto& i : graph[v])
					if ((mask & (1 << (i - 1))) == 0)
						path[mask | (1 << (i - 1))][i] = (path[mask | (1 << (i - 1))][i] + path[mask][v]) % p;
	cout << path[(1 << (n - 1)) - 1][n - 1] % p << '\n';

	return 0;
}