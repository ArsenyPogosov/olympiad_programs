//source: https://codeforces.com/gym/102348/problem/A
//status: solved

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
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	cout << max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)) << ' ';
	if (k1 > k2) { swap(a1, a2); swap(k1, k2); };
	cout << min(n / k1, a1) + min((n - min(n / k1, a1) * k1) / k2, a2);

	return 0;
}