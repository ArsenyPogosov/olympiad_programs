//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("building.in");
ofstream fout("building.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	long long n, k, x, y;
	cin >> n >> k >> x >> y;
	long long tot = n * y + n / k * (x - y), block = (k - 1) * y + x;
	long long q; cin >> q;
	while (q--)
	{
		long long a; cin >> a;
		a -= 1;
		a %= tot;
		a %= tot;
		long long res = a / block * k;
		a %= block;
		res += min(a / y, k - 1) + 1;
		cout << res << '\n';
	}

	return 0;
}