//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260745/problem/C
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	long long n, m; cin >> n >> m;
	vector<vector<long long>> Map(n, vector<long long>(m));
	for (auto& i : Map) for (auto& j : i) cin >> j;
	priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> gr;
	for (long long i = 0; i < n; ++i)
		gr.push({ Map[i][0], {i, 0} });
	for (long long i = 0; i < n; ++i)
		gr.push({ Map[i][m - 1], {i, m - 1} });
	for (long long i = 0; i < m; ++i)
		gr.push({ Map[0][i], {0, i} });
	for (long long i = 0; i < m; ++i)
		gr.push({ Map[n - 1][i], {n - 1, i} });

	long long ur = 0, count = 0;
	vector<vector<long long>> was(n, vector<long long>(m));
	while (gr.size())
	{
		long long a, b;
		a = gr.top().second.first;
		b = gr.top().second.second;
		gr.pop();
		if (was[a][b]) continue;
		was[a][b] = true;

		ur = max(ur, Map[a][b]);
		count += ur - Map[a][b];
		for (long long i = max(a - 1, 0LL); i <= min(a + 1, n - 1); ++i)
			for (long long j = max(b - 1, 0LL); j <= min(b + 1, m - 1); ++j)
				if (abs(a - i) + abs(b - j) == 1)
					if (!was[i][j])
						gr.push({ Map[i][j], {i, j} });
	}
	cout << count;

	return 0;
}