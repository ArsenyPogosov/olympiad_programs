//source: https://drive.google.com/file/d/1fUaI6mudYLqFC8slybAqDkfwzuqbj3c3/view
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

const long long INF = 10000000000000000;

int main()
{
	long long n, m; cin >> n >> m;
	vector<list<vector<long long>>> Graph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long x, y, d, s; cin >> x >> y >> d >> s; --x; --y;
		Graph[x].push_back({ y, d, s });
		Graph[y].push_back({ x, d, s });
	}
	long long t; cin >> t;
	long long l = 0, r = 1000005, res = INF;
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		vector<long long> Dist(n, INF); Dist[0] = 0;
		set<pair<long long, long long>> q; q.insert({ Dist[0], 0 });
		while (!q.empty())
		{
			long long v = q.begin()->second; q.erase(q.begin());
			if (Dist[v] == INF) break;
			for (auto&i: Graph[v])
				if (i[2] <= m)
					if (Dist[i[0]] > Dist[v] + i[1])
					{
						q.erase({ Dist[i[0]], i[0] });
						Dist[i[0]] = Dist[v] + i[1];
						q.insert({ Dist[i[0]], i[0] });
					}
		}
		if (Dist[n - 1] > t)
			l = m;
		else
		{
			r = m;
			res = Dist[n - 1];
		}
	}
	if (res == INF)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		cout << r << ' ' << res << '\n';
	}

	return 0;
}