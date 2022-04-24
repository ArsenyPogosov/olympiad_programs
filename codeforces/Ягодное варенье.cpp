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
	for (int tt = 0; tt < t; ++tt)
	{
		int n; cin >> n;
		vector<int> a(2 * n);
		for (auto& i : a) cin >> i;
		vector<int> c(n + 1);
		c[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			c[i] = c[i - 1] + (a[i - 1] == 1);
			c[i] = c[i] - (a[i - 1] == 2);
		}
		vector<set<int, greater<int>>> vs(n * 2 + 5);
		for (int i = 0; i < n + 1; ++i)
			vs[c[i] + n].insert(i);
		int cc = 0, minn = n - *vs[n].begin() + n;
		for (int i = 2 * n - 1; i >= n; --i)
		{
			cc += (a[i] == 1);
			cc -= (a[i] == 2);
			if (vs[-cc + n].size() == 0) continue;
			int nv = n - (*vs[-cc + n].begin()) + i - n;
			minn = min(minn, nv);
		}
		cout << minn << '\n';
	}

	return 0;
}