#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int64_t n; int64_t k; cin >> n >> k;
	vector<int64_t> h(n), g(n);
	for (int64_t i = 0; i < n; ++i)
		cin >> h[i] >> g[i];

	if (n == 1)
	{
		cout << (g[0] >= k) << '\n';
		return 0;
	}

	int64_t m = n / 2;
	vector<pair<int64_t, int64_t>> a, b;
	for (int64_t mask = 0; mask < (1 << m); ++mask)
	{
		bool good = true;
		int64_t prev = 0;
		int64_t cnt = 0;
		for (int64_t i = 0; i < m; ++i)
			if ((mask >> i) & 1)
			{
				if (prev > h[i])
				{
					good = false;
					break;
				}
				prev = h[i];

				cnt += g[i];
			}

		if (good)
			a.emplace_back(prev, cnt);
	}
	for (int64_t mask = 0; mask < (1 << (n-m)); ++mask)
	{
		bool good = true;
		int64_t prev = 1e9;
		int64_t cnt = 0;
		for (int64_t i = n - m - 1; i >= 0; --i)
			if ((mask >> i) & 1)
			{
				if (prev < h[i + m])
				{
					good = false;
					break;
				}
				prev = h[i + m];

				cnt += g[i + m];
			}

		if (good)
			b.emplace_back(prev, cnt);
	}
	sort(a.begin(), a.end(), [](pair<int64_t, int64_t> l, pair<int64_t, int64_t> r) { return l.first > r.first || l.first == r.first && l.second < r.second; });
	sort(b.begin(), b.end());

	int64_t res = 0, lcg = -1;
	vector<int64_t> cur;
	int64_t it = 0;
	for (auto& bb : b)
	{
		int64_t ch = bb.first, cg = bb.second;
		bool flag = false;
		while (a.size() && a.back().first <= ch)
		{
			flag = true;
			cur.push_back(a.back().second);
			a.pop_back();
		}
		if (flag)
			sort(cur.begin(), cur.end(), greater<int64_t>());

		if (lcg > cg)
			it = 0;
		lcg = cg;

		while (it < cur.size() && cur[it] + cg >= k) ++it;
		res += it;
	}

	cout << res << '\n';

	return 0;
}