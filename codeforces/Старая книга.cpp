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
	long long k, s; cin >> k >> s;
	long long i = 1, sum;
	for (;; ++i)
	{
		sum = i * (2 * k + 1 + i) / 2;
		if (sum >= s)
			break;
	}
	if (sum == s)
	{
		cout << k << '\n';
		return 0;
	}
	sum -= k + i;
	--i;
	cout << k + (s - sum + i - 1) / i << '\n';

	return 0;
}