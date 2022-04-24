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
	long long x, xx; cin >> x; xx = x;
	if (x == 1)
	{
		cout << 1 << ' ' << 1;
		return 0;
	}
	vector<long long> p;
	for (long long i = 2; i * i <= x; ++i)
	{
		long long res = 1;
		while (x % i == 0)
		{
			x /= i;
			res *= i;
		}
		if (res != 1) p.push_back(res);
	}
	p.push_back(x);
	sort(p.begin(), p.end());
	long long n = p.size();
	long long best = xx;
	for (long long mask = 0; mask < (2 << n); ++mask)
	{
		long long tek = 1;
		for (long long i = 0; i < n; ++i)
			if (mask & (1 << i))
				tek *= p[i];
		best = min(best, max(tek, xx/tek));
	}
	cout << best << ' ' << xx / best << '\n';

	return 0;
}