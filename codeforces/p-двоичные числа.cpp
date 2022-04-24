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

long long hc = 31;
long long n, p;

long long cp(long long x)
{
	long long res = 0;
	while (x > 0)
	{
		res += x % 2;
		x = x >> 1;
	}
	return res;
}

bool check(long long m)
{
	return (cp(n - p * m) <= m) && (m <= n - p * m);
}

int main()
{
	cin >> n >> p;
	for (int m = 1; m <= hc; ++m)
		if (check(m))
		{
			cout << m;
			return 0;
		}
	if (p >= 0)
	{
		long long mam = n / (p + 1);
		if (hc + 1 <= mam)
			cout << hc + 1;
		else
			cout << -1;
	}
	if (p == -1)
	{
		cout << hc + 1;
	}
	if (p <= -2)
	{
		long long mim = (n + p) / (p + 1);
		cout << max(mim, hc + 1);
	}
	return 0;
}