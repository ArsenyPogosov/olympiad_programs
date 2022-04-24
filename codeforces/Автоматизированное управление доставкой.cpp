//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("delivery.in");
ofstream fout("delivery.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	long long k, x, y;
	cin >> k >> x >> y;
	long long n = y / x;
	if ((y - n * x) <= n * (k - 1))
		cout << y << '\n';
	else
		cout << (n + 1) * x << '\n';

	return 0;
}