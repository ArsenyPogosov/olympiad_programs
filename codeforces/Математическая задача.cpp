//source: https://codeforces.com/contest/1262/problem/A
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
	int tt; cin >> tt;
	for (int ttt = 0; ttt < tt; ++ttt)
	{
		int n; cin >> n;
		int mmin = INT_MAX, mmax = -1;
		for (int i = 0; i < n; ++i)
		{
			int a, b; cin >> a >> b; mmin = min(mmin, b); mmax = max(mmax, a);
		}
		cout << max(mmax - mmin, 0) << '\n';
	}

	return 0;
}