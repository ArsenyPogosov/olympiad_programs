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

long long best = 1e18;

long long k;

void smooth(long long d1)
{
	long long d2 = k / d1;
	if (d1 - d2 >= 0 && d1 + d2 >= 0 && ((d1 - d2) % 2 == 0))
		best = min(best, (d1 + d2) / 2);
}

int main()
{
	cin >> k;
	if (k == 0)
	{
		cout << "0\n";
		return 0;
	}

	for (long long i = 1; i * i <= abs(k); ++i)
		if (k % i == 0)
		{
			smooth(i);
			smooth(-i);
			smooth(k/i);
			smooth(-k/i);
		}
	if (best == 1e18)
		cout << "none\n";
	else
		cout << best << '\n';

	return 0;
}