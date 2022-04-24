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
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	vector<long long> c(2);
	for (long long i = 0; i < n; ++i)
	{
		c[i % 2] += (a[i] + 1) / 2;
		c[(i + 1) % 2] += a[i] / 2;
	}
	cout << min(c[0], c[1]);

	return 0;
}