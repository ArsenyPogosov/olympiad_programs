//source: file:///C:/Users/arsen/Downloads/13.11.19.%201%20%D0%B3%D1%80%D1%83%D0%BF%D0%BF%D0%B0.%20%D0%94%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D0%BA%D0%B0%20%D0%BF%D0%BE%20%D0%BF%D0%BE%D0%B4%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%B0%D0%BC%20%D0%B8%20%D0%BF%D1%80%D0%BE%D1%84%D0%B8%D0%BB%D1%8E.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("g3.in");
ofstream fout("g3.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<long long> bs;
long long n;

long long conf(long long a, long long b, long long c, long long d)
{
	return a * 8 + b * 4 + c * 2 + d;
}

bool ok(long long a, long long b, long long c, long long d)
{
	return find(bs.begin(), bs.end(), conf(a, b, c, d)) != bs.end();
}

long long get(long long mask, long long i)
{
	return (mask >> i) & 1;
}

bool ok(long long a, long long b)
{
	for (long long i = 0; i < n - 1; ++i)
		if (!ok(get(a, i), get(b, i), get(a, i + 1), get(b, i + 1))) 
			return false;
	return true;
}

int main()
{
	long long m, q; cin >> n >> m >> q;
	bs.resize(q);
	for (auto&i : bs)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		i = conf(a, b, c, d);
	}
	vector<list<long long>> graph(1 << n);
	for (long long i = 0; i < (1 << n); ++i)
		for (long long j = 0; j < (1 << n); ++j)
			if (ok(i, j))
				graph[i].push_back(j);
	vector<vector<long long>> dp(m, vector<long long>(1 << n));
	for (long long mask = 0; mask < (1 << n); ++mask) dp[0][mask] = 1;
	for (long long i = 0; i < m - 1; ++i)
		for (long long mask = 0; mask < (1 << n); ++mask)
			for (auto& k : graph[mask])
				dp[i + 1][k] += dp[i][mask];
	long long count = 0;
	for (long long mask = 0; mask < (1 << n); ++mask) count += dp[m - 1][mask];
	cout << count;

	return 0;
}