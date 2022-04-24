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

int ans(int d, int n)
{
	if (d == 0) return 0;
}

int main()
{
	long long t; cin >> t;
	for (long long tt = 0; tt < t; ++tt)
	{
		long long a, b; cin >> a >> b;
		long long n = 0;
		for (; n < 400000; ++n)
		{
			if ((n * (n + 1) / 2 + b - a) % 2 != 0) continue;
			long long k = (n * (n + 1) / 2 + b - a) / 2;
			if ((0 <= k) && (k <= n * (n + 1) / 2))
				break;
		}
		cout << n << '\n';
	}

	return 0;
}