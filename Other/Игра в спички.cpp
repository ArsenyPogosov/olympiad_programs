#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		int mn = -1, mx = -1;
		for (int i = 1; (n - i) / (2 * i + 1) >= i; ++i)
		{
			if (((n - i) % (2 * i + 1))) continue;

			int tek = (n - i - (n - i) / (2 * i + 1)) / 2;
			if (mn == -1)
			{
				mn = mx = tek;
			}

			mn = min(mn, tek);
			mx = max(mx, tek);
		}

		if (mn == -1)
			cout << "-1\n";
		else
			cout << mn << ' ' << mx << '\n';
	}

	return 0;
}