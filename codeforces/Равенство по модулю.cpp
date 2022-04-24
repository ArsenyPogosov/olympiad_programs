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
	long long n, m; cin >> n >> m;
	vector<long long> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	sort(b.begin(), b.end());
	long long bb = m + 1;
	for (long long i = 0; i < n; ++i)
	{
		long long d = (b[i] - a[0] + m * 2) % m;
		vector<long long> na = a;
		for (auto& i : na) i = (i + d) % m;
		sort(na.begin(), na.end());
		bool flag = true;
		for (long long i = 0; i < n; ++i)
			if (na[i] != b[i])
			{
				flag = false;
				break;
			}
		if (flag) bb = min(bb, d);
	}
	cout << bb;

	return 0;
}