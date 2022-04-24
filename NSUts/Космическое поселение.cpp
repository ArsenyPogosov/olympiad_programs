//source: file:///C:/Users/arsen/Downloads/1%20(3).pdf
//status: solved

#include <bits/stdc++.h>
using namespace std;
#define f_io
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
	long long n, a, b, w, h;
	cin >> n >> a >> b >> w >> h;
	long long l = 0, r = w + 1;
	while (l + 1 < r)
	{
		long long d = (l + r) / 2;
		if (max((w / (a + 2 * d)) * (h / (b + 2 * d)), (h / (a + 2 * d)) * (w / (b + 2 * d))) >= n)
			l = d;
		else
			r = d;
	}
	cout << l;

	return 0;
}