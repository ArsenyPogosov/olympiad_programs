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

long long Usqrt(long long x)
{
	long long s = sqrt(x);
	for (long long i = max(s - 10, 0ll); i <= s + 10; ++i)
		if (i * i >= x)
			return i;
}

long long Dsqrt(long long x)
{
	long long s = sqrt(x);
	for (long long i = s + 10; i >= max(s - 10, 0ll); --i)
		if (i * i <= x)
			return i;
}

long long Count(long long x, long long k, long long a, long long b)
{
	return max(0LL, Dsqrt(min(x + k, b)) - Usqrt(max(x - k, a)) + 1);
}

int main()
{
	long long a, b, k; cin >> a >> b >> k;
	long long res = 0;
	for (long long i = 1; i * i * i <= b; ++i)
	{
		long long x = i * i * i;
		if (x >= a)
			res += Count(x, k, a, b);
	}
	cout << res << '\n';

	return 0;
}