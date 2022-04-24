//source: https://codeforces.com/contest/1263/problem/0
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
		vector<int> a(3);
		for (auto& i : a) cin >> i;
		sort(a.begin(), a.end());
		int res = 0;
		res = min(a[2] - a[1], a[0]);
		a[0] -= res;
		a[2] -= res;
		res += a[0];
		a[1] -= (a[0] + 1) / 2;
		a[2] -= a[0] / 2;
		res += a[1];
		cout << res << '\n';
	}

	return 0;
}