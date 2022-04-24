#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	long long a, b; cin >> b >> a;
	if (b <= 3)
	{
		a %= (1ll << (b + 2));
		long long res = 1;
		for (int i = 0; i < (1ll << b); ++i)
			res *= a;
		cout << res % (1ll << (b + 2)) << '\n';
		return 0;
	}
	cout << (a % 2) << '\n';

	return 0;
}