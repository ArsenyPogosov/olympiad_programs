//source: https://codeforces.com/contest/1225/problem/B2
//status: coding

#include <bits/stdc++.h>
#include <map>
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
	int t;
	cin >> t;
	for (; t > 0; --t)
	{
		map<int, int> f;
		int n, k, d;
		cin >> n >> k >> d;
		int res = n + 1;
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		for (int i = 0; i < d; ++i)
			++f[a[i]];
		res = min(res, int(f.size()));
		for (int i = d; i < n; ++i)
		{
			--f[a[i - d]]; ++f[a[i]];
			if (f[a[i - d]] == 0) f.erase(a[i - d]);
			res = min(res, int(f.size()));
		}
		cout << res << '\n';
	}

	return 0;
}