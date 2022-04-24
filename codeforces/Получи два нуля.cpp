//source: https://codeforces.com/contest/1260/problem/B
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
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		if (a * 2 >= b && (a + b) % 3 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}