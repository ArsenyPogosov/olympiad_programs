//source: https://codeforces.com/contest/1260/problem/C
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

long long GCD(long long a, long long b)
{
	return (b == 0 ? a : GCD(b, a % b));
}

int main()
{
	long long n; cin >> n;
	for (long long i = 0; i < n; ++i)
	{
		long long r, b, k, g; cin >> r >> b >> k;
		g = GCD(r, b); r /= g; b /= g;
		if (r > b) swap(r, b);
		if (r * (k - 1) + 1 < b)
			cout << "REBEL\n";
		else
			cout << "OBEY\n";
	}

	return 0;
}