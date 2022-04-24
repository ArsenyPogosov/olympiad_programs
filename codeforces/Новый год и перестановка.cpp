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
	long long n, m; cin >> n >> m;
	vector<long long> F(1000000);
	F[0] = 1;
	for (long long i = 1; i < 1000000; ++i)
		F[i] = (F[i - 1] * i) % m;
	long long res = 0;
	for (long long l = 1; l <= n; ++l)
	{
		long long add = ((((n - l + 1) * F[l] % m) * (F[n - l])) % m) * (n - l + 1) % m;
		res = (res + add) % m;
	}
	cout << res << '\n';

	return 0;
}