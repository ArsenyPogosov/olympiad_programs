#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		long long h, c, t; cin >> h >> c >> t;
		long long l = 0, r = 1e9;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if ((m * (h + c) + h) >= t * (2 * m + 1))
				l = m;
			else
				r = m;
		}
		int a = l, b = l + 1;
		if (abs((a * (h + c) + h) - t * (2 * a + 1)) * (2 * b + 1) > abs((b * (h + c) + h) - t * (2 * b + 1)) * (2 * a + 1))
			swap(a, b);
		if (abs((a * (h + c) + h) - t * (2 * a + 1)) * 2 >= abs((h + c) - t * 2) * (2 * a + 1))
			cout << 2 << '\n';
		else
			cout << a * 2 + 1 << '\n';
	}

	return 0;
}