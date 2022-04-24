//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258385/problems
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
	long long n;
	cin >> n;
	map<long long, long long> a;
	for (long long i = 0; i < n; ++i) { long long h; cin >> h; ++a[h]; }
	long long res = 0;
	for (auto& i : a)
	{
		for (long long  pow = 1; pow < (2 * 1000000000); pow *= 2)
		{
			if (a.find(pow - i.first) != a.end())
			{
				if (i.first != pow - i.first)
				{
					res += i.second * a[pow - i.first];
				}
				else
				{
					res += i.second * (i.second - 1);
				}
			}
		}
	}
	cout << res / 2;

	return 0;
}