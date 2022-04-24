//source: 
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

long long n, k;
vector<list<pair<long long, long long>>> Graph;
vector<pair<long long, long long>> dp;

void DFS(long long v, long long p = -1)
{
	long long sum = 0;
	multiset<long long> m;
	for (auto& i : Graph[v])
		if (i.first != p)
		{
			DFS(i.first, v);
			sum += dp[i.first].second;
			m.insert({ i.second - dp[i.first].second + dp[i.first].first });
		}
	long long count = 1;
	dp[v].first = dp[v].second = sum;
	while (count <= k && !m.empty())
	{
		long long toadd = *(--m.end());
		if (toadd < 0) break;
		if (count < k) dp[v].first += toadd;
		dp[v].second += toadd;
		m.erase(--m.end());
		++count;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long q; cin >> q;
	for (long long t = 0; t < q; ++t)
	{
		cin >> n >> k;
		Graph = vector<list<pair<long long, long long>>>(n);
		for (long long i = 0; i < n - 1; ++i)
		{
			long long a, b, c; cin >> a >> b >> c; --a; --b;
			Graph[a].push_back({ b, c });
			Graph[b].push_back({ a, c });
		}
		dp = vector<pair<long long, long long>>(n);
		DFS(0);
		cout << dp[0].second << '\n';
	}

	return 0;
}