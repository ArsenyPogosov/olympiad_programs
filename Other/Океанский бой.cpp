#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int64_t INF = 1e9;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int64_t n, m; cin >> n >> m;

	int64_t res = -1;	
	vector<vector<pair<int64_t, int64_t>>> open(n + 1), close(n + 1);
	int64_t k; cin >> k;
	for (int64_t i = 0; i < k; ++i)
	{
		int64_t x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		res = max(res, (x2 - x1) * (y2 - y1));
		x1 = max(int64_t(0), x1 - 1);
		x2 = min(n, x2 + 1);
		y1 = max(int64_t(0), y1 - 1);
		y2 = min(m, y2 + 1);

		open[x1].emplace_back(y1, y2);
		close[x2].emplace_back(y1, y2);
	}

	vector<int64_t> current(m);
	vector<int64_t> ord(m);
	iota(ord.begin(), ord.end(), 0);
	for (int64_t i = 0; i <= n; ++i)
	{
		for (auto& j : close[i])
			for (int64_t k = j.first; k < j.second; ++k)
				++current[k];
		if (close[i].size() > 0 || (i > 0 && open[i - 1].size() > 0))
			sort(ord.begin(), ord.end(), [&](int64_t a, int64_t b) { return current[a] > current[b]; });

		vector<int64_t> d(m + 1, -1);
		auto add = [&](int64_t i) -> int64_t {
			int64_t l = (i > 0 && d[i - 1] != -1 ? d[i - 1] : i), r = (i < m && d[i + 1] != -1 ? d[i + 1] : i);
			d[l] = r;
			d[r] = l;

			return r - l + 1;
		};

		for (auto& j : ord)
			res = max(res, current[j] * add(j));

		for (auto& j : open[i])
			for (int64_t k = j.first; k < j.second; ++k)
				current[k] = min(current[k] - 1, (int64_t)-1);
		for (auto& j : current) if (j >= 0) ++j;
	}

	cout << res << '\n';

	return 0;
}