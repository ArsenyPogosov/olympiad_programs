//source: https://codeforces.com/contest/1260/problem/A
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
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int c, sum; cin >> c >> sum;
		int d = (sum % c), p = sum / c;
		cout << p * p * (c - d) + (p + 1) * (p + 1) * d << '\n';
	}

	return 0;
}