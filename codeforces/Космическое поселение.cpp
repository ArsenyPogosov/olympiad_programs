//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("space.in");
ofstream fout("space.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	long long n, a, b, w, h; cin >> n >> a >> b >> w >> h;
	long long l = 0, r = w;
	while (l + 1 < r)
	{
		long long d = (l + r) / 2;
		if (((w / (a + 2 * d)) * (h / (b + 2 * d)) < n) &&
			((h / (a + 2 * d)) * (w / (b + 2 * d))) < n)
			r = d;
		else
			l = d;
	}
	cout << l << '\n';

	return 0;
}