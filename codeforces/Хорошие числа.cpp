//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259655/problem/R
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
	vector<long long> tp; tp.reserve(40);
	for (long long i = 1; i < 9000000000000000000; i *= 3) tp.push_back(i);
	long long q; cin >> q;
	for (long long bbbb = 0; bbbb < q; ++bbbb)
	{
		long long n; cin >> n;
		long long m, i;
		for (i = 0, m = 0; m < n; ++i) m += tp[i];
		for (; i >= 0; --i) if (m - tp[i] >= n) m -= tp[i];
		cout << m << '\n';
	}

	return 0;
}