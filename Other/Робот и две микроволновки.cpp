#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ifstream cin("robot.in");
	ofstream cout("robot.out");

	int ttt; cin >> ttt;
	while (ttt--)
	{
		int n, a, b; cin >> n >> a >> b;
		vector<int> c(n);
		for (auto& i : c) cin >> i;
		vector<int> cm(1 << n);
		for (int mask = 1; mask < (1 << n); ++mask)
			for (int i = 0; i < n; ++i)
				if (mask & (1 << i))
				{
					cm[mask] = cm[mask ^ (1 << i)] + c[i];
					break;
				}

		vector<int> ares(1 << n, 1e9); ares[0] = 0;
		for (int mask = 1; mask < (1 << n); ++mask)
			for (int submask = mask; submask; submask = (submask - 1) & mask)
				if (cm[submask] <= a)
					ares[mask] = min(ares[mask], ares[mask ^ submask] + 1);

		vector<int> bres(1 << n, 1e9); bres[0] = 0;
		for (int mask = 1; mask < (1 << n); ++mask)
			for (int submask = mask; submask; submask = (submask - 1) & mask)
				if (cm[submask] <= b)
					bres[mask] = min(bres[mask], bres[mask ^ submask] + 1);
		
		int res = 1e9;
		for (int mask = 0; mask < (1 << n); ++mask)
			res = min(res, max(ares[mask], bres[((1 << n) - 1) ^ mask]));
		cout << res << '\n';
	}

	return 0;
}