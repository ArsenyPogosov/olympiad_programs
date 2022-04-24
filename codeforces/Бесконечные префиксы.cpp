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
		long long n, x; cin >> n >> x;
		vector<long long> c(n * 2 + 5, 0);
		long long tek = 0;
		for (long long i = 0; i < n; ++i)
		{
			++c[tek + n + 1];
			char h; cin >> h;
			if (h == '0') 
				++tek;
			else
				--tek;
		}
		if (tek == 0)
		{
			long long ch = x + n + 1, p = 0;
			if (0 <= ch && ch < n * 2 + 5)
				p = c[ch];
			if (p > 0)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
			continue;
		}
		long long count = 0;
		for (long long i = 0; i < n * 2 + 5; ++i)
		{
			long long cur = i - n - 1;
			if (((x - cur) % (tek) == 0) && ((x - cur) / (tek) >= 0)) count += c[i];
		}
		cout << count << '\n';
	}

	return 0;
}