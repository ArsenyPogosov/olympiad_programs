//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("calc.in");
ofstream fout("calc.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	while (b--) n = (n + 1) / 2;
	while (a--) n /= 2;
	while (n && c--) n = (n - 1) / 2;
	cout << n << '\n';

	return 0;
}