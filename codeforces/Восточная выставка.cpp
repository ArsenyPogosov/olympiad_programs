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
		vector<int> x(n), y(n);
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		cout << (n % 2 ? 1 : (x[n / 2] - x[n / 2 - 1] + 1) * 1ll * (y[n / 2] - y[n / 2 - 1] + 1)) << '\n';
	}

	return 0;
}