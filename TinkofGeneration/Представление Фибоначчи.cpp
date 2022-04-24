#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	int m = 201;
	vector<int> tek(m);
	for (int t = 0; t < n; ++t)
	{
		{
			int h; cin >> h; ++tek[h];
		}
		for (int i = 2; i < m; ++i)
		{
			int h = min(tek[i - 2], tek[i - 1]);
			tek[i - 2] -= h;
			tek[i - 1] -= h;
			tek[i] += h;
		}

		int dp0 = 0, dp1 = 1, d = 0;
		for (int i = 1; i < m; ++i)
		{
			++d;
			if (!tek[i]) continue;
			int h = dp0;
			dp0 = (dp0 * (((d + 2) / 2-1)) + dp1 * (((d + 1) / 2)-1)) % p;
			dp1 += h;
			d = 0;
		}

		cout << (dp0 + dp1) % p << '\n';
	}

	return 0;
}