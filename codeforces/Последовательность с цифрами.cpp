#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long a, k; cin >> a >> k;
		while (k > 1)
		{
			long long tk = a, mn = 10, mx = -1;
			while (tk)
			{
				mn = min(mn, tk % 10);
				mx = max(mx, tk % 10);
				tk /= 10;
			}
			a += mn * mx;
			if (mn == 0) break;
			--k;
		}
		cout << a << '\n';
	}

	return 0;
}