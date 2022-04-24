#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int mx = 0, t;
	for (int i = 0; i < n; ++i)
		cin >> t, mx = max(mx, t);

	if (n == 1)
	{
		cout << mx << '\n';
		return 0;
	}

	if (n == 2)
	{
		cout << mx + m << '\n';
		return 0;
	}

	cout << mx + (m + n - 1 - 1) / (n - 1) << '\n';

	return 0;
}