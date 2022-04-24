#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 100000;

int mpop(int mask, int i)
{
	return mask ^ (1 << i);
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i] >> c[i];

	vector<pair<int, int>> dp(1 << n, { -INF, -INF });
	vector<int> p(1 << n, -1);
	dp[0] = { 0, k };
	for (int mask = 1; mask < (1 << n); ++mask)
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
			{
				int nmask = mpop(mask, i);
				if (dp[nmask] != pair<int, int>{-INF, -INF}) //For MK. Code doesnt compile without pair<int, int> in my vs c++11!   
					if (a[i] <= dp[nmask].second && dp[mask ^ (1 << i)].second <= b[i])
					{
						dp[mask].first = dp[nmask].first + 1;
						dp[mask].second = dp[nmask].second + c[i];
						p[mask] = i;
						break;
					}
			}

	int maxx = 0;
	for (int mask = 1; mask < (1 << n); ++mask)
		if (dp[maxx].first < dp[mask].first)
			maxx = mask;
	int cur = maxx;
	vector<int> res;
	res.reserve(n);
	while (p[cur] != -1)
	{
		res.push_back(p[cur]);
		cur = mpop(cur, p[cur]);
	}
	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	for (auto&i : res)
		cout << i + 1 << ' ';

	return 0;
}