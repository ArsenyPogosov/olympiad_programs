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
		int n, m, k; cin >> n >> m >> k; k = min(k, m - 1);
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		int best = -1;
		vector<int> ans(m);
		for (int i = 0; i < m; ++i) ans[i] = max(a[i], a[n - 1 - (m - 1 - i)]);
		for (int i = 0; i <= k; ++i)
		{
			int nbest = 1e9;
			for (int j = i; j - i <= m - k - 1; ++j)
				nbest = min(nbest, ans[j]);
			best = max(best, nbest);
		}
		cout << best << '\n';
	}

	return 0;
}