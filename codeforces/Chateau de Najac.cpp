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
	vector<long long> mass(n);
	for (auto& i : mass) cin >> i;
	long long d; cin >> d;
	sort(mass.begin(), mass.end());
	double sum = 0;
	for (auto& i : mass) sum += i;
	for (long long i = 0; i < n / 3; ++i)
		sum -= double(mass[n - i - 1]) / 100.0 * d;
	cout << fixed << setprecision(16) << sum;

	return 0;
}