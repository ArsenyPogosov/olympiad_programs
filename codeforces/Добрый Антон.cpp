#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (auto& i : a) cin >> i;
		for (auto& i : b) cin >> i;
		int wm = 0, wg = 0, g = 1;
		for (int i = 0; i < n; ++i)
		{
			if ((a[i] > b[i]) && (wm == 0))
			{
				g = 0;
				break;
			}
			if ((a[i] < b[i]) && (wg == 0))
			{
				g = 0;
				break;
			}
			if (a[i] == 1) wg = 1;
			if (a[i] == -1) wm = 1;
		}
		if (g == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}