//source: http://neerc.ifmo.ru/school/io/archive/20191019/problems-20191019-advanced.pdf
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
	long long n, m, k;
	cin >> n >> m >> k;
	vector< long long> a(n), as(n);
	for (auto& i : a) cin >> i;
	partial_sum(a.begin(), a.end(), as.begin());
	vector< long long> scopes(n + 1, 0);
	long long res = 0;
	for (long long i = 0; i < m; ++i)
	{
		long long l, r;
		cin >> l >> r; --l; --r;
		++scopes[l]; --scopes[r + 1];
		res += as[r] - (l > 0 ? as[l - 1] : 0);
	}
	vector<pair< long long, long long>> sa(n);
	for (long long i = 0; i < n; ++i) sa[i] = { 0, a[i] };
	long long count = 0;
	for (long long i = 0; i < n; ++i)
	{
		count += scopes[i];
		sa[i].first = -count;
	}
	sort(sa.begin(), sa.end());
	long long i = 0;
	while (i < n && k > 0)
	{
		long long d = min(k, sa[i].second);
		k -= d;
		res += sa[i].first * d;
		++i;
	}
	cout << res;

	return 0;
}