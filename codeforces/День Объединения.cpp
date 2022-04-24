//source: https://drive.google.com/file/d/1W9UCJV9ZvVCEOnb0MydlVIah0qfC6NUH/view
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("unionday.in");
ofstream fout("unionday.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

const long long INF = 10000000000000000;

vector<pair<long long, long long>> p;

long long d(long long a, long long b)
{
	return (p[a].first - p[b].first) * (p[a].first - p[b].first) + 
		(p[a].second - p[b].second) * (p[a].second - p[b].second);
}

int main()
{
	long long n; cin >> n;
	p.resize(n); for (auto& i : p) cin >> i.first >> i.second;
	vector<long long> take(n, false), dist(n, INF); dist[0] = 0;
	double res = 0;
	for (long long c = 0; c < n; ++c)
	{
		long long toadd = -1;
		for (long long i = 0; i < n; ++i)
			if (!take[i])
				if (toadd == -1 || dist[i] < dist[toadd])
					toadd = i;
		take[toadd] = true;
		res += sqrt(double(dist[toadd]));
		for (long long i = 0; i < n; ++i)
			if (!take[i])
				dist[i] = min(dist[i], d(i, toadd));
	}
	cout << fixed << setprecision(16) << res;

	return 0;
}