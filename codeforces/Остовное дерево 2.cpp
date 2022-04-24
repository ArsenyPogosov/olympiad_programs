//source: https://drive.google.com/file/d/1W9UCJV9ZvVCEOnb0MydlVIah0qfC6NUH/view
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("maxincycle.in");
ofstream fout("maxincycle.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<long long> dsu, r;

long long get(long long x)
{
	return (dsu[x] == -1 ? x : dsu[x] = get(dsu[x]));
}

bool con(long long x, long long y)
{
	return get(x) == get(y);
}

void unite(long long x, long long y)
{
	x = get(x); y = get(y);
	if (x == y) return;
	if (r[x] > r[y]) swap(x, y);
	dsu[x] = y;
	if (r[x] == r[y]) ++r[y];
}

void buildDSU(long long n)
{
	dsu.resize(n, -1); r.resize(n);
}

int main()
{
	long long n, m; cin >> n >> m;
	vector<pair<long long, pair<long long, long long>>> brunch(m);
	for (auto& i : brunch) cin >> i.second.first >> i.second.second >> i.first;
	sort(brunch.begin(), brunch.end());
	buildDSU(n);
	long long res = 0;
	for (long long i = 0; i < m; ++i)
	{
		if (!con(brunch[i].second.first - 1, brunch[i].second.second - 1))
		{
			res += brunch[i].first;
			unite(brunch[i].second.first - 1, brunch[i].second.second - 1);
		}
	}
	cout << res;

	return 0;
}