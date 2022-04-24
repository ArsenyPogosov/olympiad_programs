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

long long ansk(long long x, long long k)
{
	if (k == 0) return 0;
	x -= (1LL << k);
	if (x < 0) return 0;
	x /= (1LL << (k + 1));
	return x + 1;
}

int main()
{
	long long l, r; cin >> l >> r;
	long long res = 0;
	for (int i = 1; i < 62; ++i)
		res += (ansk(r, i) - ansk(l - 1, i)) * i;
	cout << res;

	return 0;
}