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
		vector<long long> a(36);
		for (long long i = 0; i < m; ++i)
		{
			long long h, c = 0; cin >> h;
			while (h != 1)
			{
				++c; h /= 2;
			}
			++a[c];
		}
		vector<long long> b(65);
		long long c = 0, nn = n;
		while (nn != 0)
		{
			b[c] = nn % 2;
			++c; nn/= 2;
		}
		long long count = 0, res = 0;
		bool flag = false;
		for (long long i = 0; i < 65; ++i)
		{
			if (i < 35) count += a[i] * (1ll << i);
			if (b[i])
			{
				if (count >= (1ll << i))
				{
					count -= (1ll << i);
					continue;
				}
				long long j = i;
				for (; j < 35; ++j)
					if (a[j]) break;
				if (j >= 35)
				{
					cout << "-1\n";
					flag = true;
				}
				for (; j > i; --j)
				{
					--a[j];
					a[j - 1] += 2;
					++res;
				}
			}
		}
		if (flag) continue;
		cout << res << '\n';
	}

	return 0;
}