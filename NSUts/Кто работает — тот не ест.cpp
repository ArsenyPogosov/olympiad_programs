#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		long long p, q, a, b; cin >> p >> q >> a >> b;
		long long k = (100 - p) * q - (100 - q) * a * p * b, f = b * (100 - q) * p - b * (100 - p) * q;
		k = -k; f = -f;
		long long res = -1;
		if (k > 0)
		{
			res = f / k;
			if (f % k) ++res;
			res = max(res, 1ll);
		}
		cout << res << '\n';
	}


	return 0;
}