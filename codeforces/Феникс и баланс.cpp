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
		long long res = (1ll << n);
		for (int i = n - 1; i >= n / 2; --i) res -= (1ll << i);
		for (int i = n / 2 - 1; i >= 1; --i) res += (1ll << i);
		cout << res << '\n';
	}

	return 0;
}