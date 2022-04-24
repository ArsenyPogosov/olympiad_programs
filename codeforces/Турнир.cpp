//source: https://codeforces.com/contest/1260/problem/E
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
	vector<pair<long long, long long>> a(n - 1);
	bool st = false;
	for (long long i = 0; i < n; ++i)
	{
		long long m; cin >> m;
		if (m == -1)
		{
			st = true;
			continue;
		}
		a[i - st] = { (st ? m : 0), i };
	}
	sort(a.begin(), a.end());
	long long count = 0;
	int d = 1;
	for (int f = 0; f < n - 1; f += d, d *= 2)
	{
		pair<long long, long long> M = { 0, -1 };
		for (int j = f; j < f + d; ++j)
			if (a[j].second > M.second) M = a[j];
		count += M.first;
	}

	cout << count;

	return 0;
}