//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("division.in");
ofstream fout("division.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n; cin >> n;
	int a = (n - 3) / 3, b = a + 1, c = a + 2;
	if (n % 3 == 0)
		cout << a << ' ' << b << ' ' << c << '\n';
	if (n % 3 == 1)
		cout << a << ' ' << b << ' ' << c + 1 << '\n';
	if (n % 3 == 2)
		cout << a << ' ' << b + 1 << ' ' << c + 1 << '\n';

	return 0;
}