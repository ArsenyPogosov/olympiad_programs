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
		long long n, m; cin >> n >> m;
		long long k = (n - m) / (m + 1), t = (n - m) % (m + 1);
		long long s = k * k * (m + 1 - t) + (k + 1) * (k + 1) * t;
		cout << (n * (n - 1) / 2 + n) - (s + n - m) / 2 << '\n';
	}

	return 0;
}