//source: https://codeforces.com/gym/102348/problem/F
//status: solved

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

long long n;
vector<long long> A;

long long CountZero()
{
	long long res = 0;
	long long it = -1;
	for (long long i = 0; i < n; ++i)
	{
		if (A[i] == 0) it = i;
		res += i - it;
	}
	return n * (n + 1) / 2 - res;
}

long long CountPos()
{
	long long res = 0;
	long long a = -1, b = -1;
	while (b < n)
	{
		a = b;
		while (++b < n && A[b] != 0);

		long long sign = 1, c[3] = { 0, 0, 0 };
		for (long long i = a + 1, h = 0; i < b; ++i)
		{
			++c[sign + 1];
			sign *= A[i];
			res += c[sign + 1];
		}
	}
	return res;
}

int main()
{
	cin >> n;
	A.resize(n);
	for (auto& i : A)
	{
		cin >> i;
		if (i > 0) i = 1;
		if (i < 0) i = -1;
	}
	long long x = CountZero(), y = CountPos(), z = n * (n + 1) / 2 - x - y;
	cout << z << ' ' << x << ' ' << y;

	return 0;
}