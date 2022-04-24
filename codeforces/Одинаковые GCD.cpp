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

long long phi(long long n)
{
	long long res = n;
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			res -= res / i;
			while (n % i == 0)
				n /= i;
		}
	if (n > 1) res -= res / n;

	return res;
}

long long GCD(long long a, long long b)
{
	return (a == 0 ? b : GCD(b % a, a));
}

int main()
{
	long long t; cin >> t;
	while (t--)
	{
		long long a, b; cin >> a >> b;
		cout << phi(b/GCD(a, b)) << '\n';
	}

	return 0;
}