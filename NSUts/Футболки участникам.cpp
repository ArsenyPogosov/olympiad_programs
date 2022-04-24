//source: 
//status: coding

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

long long GCD(long long x, long long y)
{
	if (y == 0) return x;
	return GCD(y, x % y);
}

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;
	long long tl, tr;				  //2*(-N + 3t) + 3*(N - 2t) = N
	tl = (n + 2) / 3;				  //3t>=N => t>=N/3
	tl = max(tl, (n - b + 1) / 2);    //N-2t<=b => 2t>=N-b => t>=(N-b)/2
	tr = (n + a) / 3;				  //-N+3t<=a => t<=(N+a)/3
	tr = min(tr, n / 2);			  //N-2t>=0 => 2t<=N => t<=(N)/2
	long long x = max(tr - tl + 1, 0ll), y = (a + 1) * (b + 1), g = GCD(x, y);
	x /= g; y /= g;
	if (x == 0)
	{
		cout << 0;
	}
	else
	{
		if (x == y)
		{
			cout << 1;
		}
		else
		{
			cout << x << '/' << y;
		}
	}

	return 0;
}