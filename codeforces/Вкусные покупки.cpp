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
	long long t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		vector<long long> a(n);
		for (auto& i : a) cin >> i;
		bool flag = false;
		long long sum = 0;
		for (long long i = 0; i < n - 1; ++i)
		{
			sum += a[i];
			if (sum <= 0)
			{
				flag = true;
				break;
			}
		}
		sum = 0;
		for (long long i = n - 1; i > 0; --i)
		{
			sum += a[i];
			if (sum <= 0)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}