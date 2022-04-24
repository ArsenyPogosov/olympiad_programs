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
	long long n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long long x; cin >> x;
		if ((0 < (x % 14) && (x % 14) < 7) && x > 14)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}