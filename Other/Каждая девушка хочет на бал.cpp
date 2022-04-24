#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> morder(n); iota(morder.begin(), morder.end(), 0);
	vector<pair<int, int>> man(n);
	for (auto& i : man)
		cin >> i.first >> i.second;
	sort(morder.begin(), morder.end(), [&](int a, int b) {
		return man[a].first < man[b].first;
	});

	int m; cin >> m;
	vector<int> worder(m); iota(worder.begin(), worder.end(), 0);
	vector<pair<int, int>> woman(m);
	for (auto& i : woman)
		cin >> i.first >> i.second;
	sort(worder.begin(), worder.end(), [&](int a, int b) {
		return woman[a].second < woman[b].second;
	});

	int t = 0;
	vector<pair<int, int>> res;
	set<pair<int, int>> ready;

	for (auto& i : morder)
	{
		while (t < m && man[i].first >= woman[worder[t]].second)
		{
			ready.emplace(woman[worder[t]].first, worder[t]);
			++t;
		}

		auto p = lower_bound(ready.begin(), ready.end(), pair<int, int>{man[i].second, -1});
		if (p != ready.end())
		{
			res.emplace_back(i, p->second);
			ready.erase(p);
		}
	}

	cout << res.size() << '\n';
	for (auto& i : res)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}