//source: http://neerc.ifmo.ru/school/sirius-2019/problems/20191111.pdf
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

long long SqSum(long long n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

int main()
{
	long long q;
	cin >> q;
	for (long long i = 0; i < q; ++i)
	{
		long long n, m;
		cin >> n >> m;
		long long k = min(n, m) - 1;
		cout << n * m * (k + 1) - k * (k + 1) / 2 * (n + m) + SqSum(k) << '\n';
	}


	return 0;
}