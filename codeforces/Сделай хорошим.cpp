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
	int ttt; cin >> ttt;
	while (ttt--)
	{
		int n; cin >> n;
		long long sum = 0, xr = 0;
		for (int i = 0; i < n; ++i)
		{
			long long h; cin >> h;
			sum += h;
			xr ^= h;
		}
		cout << 2 << '\n' << xr << ' ' << sum + xr << '\n';
	}

	return 0;
}