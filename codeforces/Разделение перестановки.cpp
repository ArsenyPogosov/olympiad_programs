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

int main()
{
	long long n; cin >> n;
	vector<long long> p(n), a(n), rp(n);
	for (int i = 0; i < n; ++i)
	{
		long long t; cin >> t; --t;
		p[i] = t;
		rp[t] = i;
	}
	for (auto& i : a) cin >> i;
	long long best = 1e18, tek = 0, nn = 0;
	for (long long i = 0; i < n - 1; ++i)
	{
		while (true)
		{
			long long tek1, tek2; tek1 = tek2 = tek;
			if (p[i] == nn) continue;
			if (p[i] < nn) tek1 -= a[i];
			if (p[i] > nn) tek1 += a[i];
			if (rp[i] < nn) tek1 -= a[rp[i]];
			if (rp[i] > nn) tek1 += a[rp[i]];
			++nn;
			if (p[i] < nn) tek2 -= a[i];
			if (p[i] > nn) tek2 += a[i];
			if (rp[i] < nn) tek2 -= a[rp[i]];
			if (rp[i] > nn) tek2 += a[rp[i]];
			tek = tek2;
			if (tek1 < tek2)
			{
				--nn;
				tek = tek1;
				break;
			}
		}
		best = min(best, tek);
	}
	cout << best << '\n';

	return 0;
}