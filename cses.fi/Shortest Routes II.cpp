#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m, q; cin >> n >> m >> q;
	vector<vector<long long>> dist(n, vector<long long>(n, INF));
	for (long long i = 0; i < n; ++i) dist[i][i] = 0;
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}

	for (long long k = 0; k < n; ++k)
		for (long long i = 0; i < n; ++i)
			for (long long j = 0; j < n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	while (q--)
	{
		long long a, b; cin >> a >> b; --a; --b;
		cout << (dist[a][b] < INF ? dist[a][b] : -1) << '\n';
	}

	return 0;
}