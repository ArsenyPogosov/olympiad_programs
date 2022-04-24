#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long res = 0, mn = 0;
	for (int i = 0; i < n; ++i)
	{
		long long h; cin >> h;
		mn = max(mn, h);
		res += mn - h;
	}
	cout << res << '\n';

	return 0;
}