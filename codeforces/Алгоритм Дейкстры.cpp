//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260258/problem/B
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

const long long INF = 10000000000000000;

int main()
{
	long long n, m; cin >> n >> m;
	vector<list<pair<long long, long long>>> Graph(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c;
		Graph[a - 1].push_back({ b - 1, c });
		Graph[b - 1].push_back({ a - 1, c });
	}
	vector<long long> Dist(n, INF), p(n, -1); Dist[0] = 0;
	set<pair<long long, long long>> q; q.insert({ Dist[0], 0 });
	while (!q.empty())
	{
		long long v = q.begin()->second; q.erase(q.begin());
		if (Dist[v] == INF) break;
		for (auto& i : Graph[v])
			if (Dist[i.first] > Dist[v] + i.second)
			{
				q.erase({ Dist[i.first], i.first });
				Dist[i.first] = Dist[v] + i.second;
				q.insert({ Dist[i.first], i.first });
				p[i.first] = v;
			}
	}

	if (Dist[n - 1] == INF)
		cout << -1;
	else
	{
		list<long long> res;
		long long it = n - 1;
		while (it >= 0)
		{
			res.push_front(it);
			it = p[it];
		}
		for (auto& i : res) cout << i + 1 << ' ';
	}

	return 0;
}