//source: https://codeforces.com/contest/1237/problem/0
//status: solved

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
	int n;
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		if (h % 2 == 0) cout << h / 2;
		else cout << (h - 1) / 2 + (k++) % 2;
		cout << '\n';
	}

	return 0;
}