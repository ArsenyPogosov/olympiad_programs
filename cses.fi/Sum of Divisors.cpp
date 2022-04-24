#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	long long res = 0;
	for (long long i = 1; i <= 1e6; ++i)
	{
		res = (res + (n / i) * i) % p;
		long long a = 1e6 + 1, b = n / i;
		if (a <= b)
		{
			long long g1 = b - a + 1, g2 = a + b;
			if (g1 % 2 == 0)
				g1 /= 2;
			else
				g2 /= 2;
			g1 %= p; g2 %= p;
			res = (res + g1 * g2) % p;
		}
	}
	cout << res << '\n';

	return 0;
}