#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int a, b; a = b = 0;
		int g = 1;
		for (int i = 0; i < n; ++i)
		{
			int c, d; cin >> c >> d;
			if (!(c - a >= d - b && (c - a) >= 0 && (d - b) >= 0))
				g = 0;
			a = c; b = d;
		}
		if (g)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}