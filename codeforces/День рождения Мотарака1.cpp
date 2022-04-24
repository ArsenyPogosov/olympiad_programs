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
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		int M = 0, mi = 1e9, ma = -1e9;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] != -1)
			{
				if (a[i + 1] != -1)
					M = max(M, abs(a[i] - a[i + 1]));
				else
				{
					mi = min(mi, a[i]);
					ma = max(ma, a[i]);
				}
			}
			else
			{
				if (a[i + 1] != -1)
				{
					mi = min(mi, a[i + 1]);
					ma = max(ma, a[i + 1]);
				}
			}
		M = max(M, (ma - mi + 1) / 2);
		cout << M << ' ' << (ma + mi) / 2 << '\n';
	}

	return 0;
}