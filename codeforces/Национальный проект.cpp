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
	long long t; cin >> t;
	while (t--)
	{
		long long n, g, b; cin >> n >> g >> b;
		long long x = (n + 1) / 2, y = x / g;
		if (x % g == 0) --y;
		long long s = y * g + min(y * b, n - x), z = (n - s);

		cout << (g + b) * y + z << '\n';
	}

	return 0;
}