#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

long long n, m;
vector<vector<pair<long long, long long>>> graph;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m; ++n;
	graph.resize(n);
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c; cin >> a >> b >> c; --a; --b;
		graph[a].emplace_back(b, c);
	}
	graph[n - 1].resize(n - 1);
	for (long long i = 0; i < n - 1; ++i)
		graph[n - 1].emplace_back(i, 0);

	vector<long long> d(n, INF), p(n, -1); d[n - 1] = 0;
	long long flag, count = 0;
	do
	{
		flag = -1; ++count;
		for (long long i = 0; i < n; ++i)
			for (auto&j: graph[i])
				if (d[j.first] > d[i] + j.second)
				{
					d[j.first] = d[i] + j.second;
					p[j.first] = i;
					flag = i;
				}
	} while (flag != -1 && count <= n);
	if (flag == -1 || count < n)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		long long v = flag;
		for (long long i = 0; i < n; ++i) v = p[v];
		long long it = v;
		vector<long long> res;
		do
		{
			res.push_back(it + 1);
			it = p[it];
		} while (it != v); res.push_back(v + 1);
		reverse(res.begin(), res.end());
		for (auto& i : res) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}