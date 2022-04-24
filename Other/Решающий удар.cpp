#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int TT; cin >> TT;
	while (TT--)
	{
		int w, d; cin >> w >> d;
		double best = 0;
		while (w--)
		{
			int n, f, m; cin >> n >> f >> m;
			int N = n * f + 1;
			long long need = d - m;
			if (need > N) continue;
			need = max(need, 0ll);
			vector<long long> dp(N);
			dp[0] = 1;
			while (n--)
			{
				for (int i = N - 1; i >= 0; --i)
				{
					dp[i] = 0;
					for (int j = 1; j <= f && j <= i; ++j)
						dp[i] += dp[i - j];
				}

			}

			long long all = accumulate(dp.begin(), dp.end(), 0ll), 
				nd = accumulate(dp.begin() + need, dp.end(), 0ll);
			double res = double(nd) / double(all);
			best = max(best, res);
		}
		cout << fixed << setprecision(16) << best << '\n';
	}

	return 0;
}