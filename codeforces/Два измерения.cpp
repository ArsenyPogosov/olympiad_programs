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
	long long l, r, a; cin >> l >> r >> a;
	long long d = r - l + 1;
	long long c1 = a - d % a, c2 = d % a, n1 = d / a, n2 = d / a + 1;
	cout << n1 * (n1 - 1) / 2 * c1 + n2 * (n2 - 1) / 2 * c2 << '\n';

	return 0;
}