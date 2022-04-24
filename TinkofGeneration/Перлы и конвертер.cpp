#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> ind(k);
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h; --h;
		ind[h].push_back(i);
	}

	vector<vector<int>> res;
	while (true)
	{
		bool good = true;
		set<pair<int, int>> s;
		for (int i = 0; i < k; ++i)
		{
			if (ind[i].size())
			{
				s.emplace(ind[i].back(), i);
				ind[i].pop_back();
			}
			else
			{
				good = false;
				break;
			}
		}
		if (!good) break;

		while (prev(s.end())->first - s.begin()->first > m)
		{
			int c = prev(s.end())->second; s.erase(prev(s.end()));
			if (ind[c].size())
			{
				s.emplace(ind[c].back(), c);
				ind[c].pop_back();
			}
			else
			{
				good = false;
				break;
			}
		}

		if (!good) break;

		res.emplace_back();
		for (auto& i : s)
			res.back().push_back(i.first);
	}

	cout << res.size() << '\n';
	for (auto& i : res)
	{
		for (auto& j : i)
			cout << j + 1 << ' ';
		cout << '\n';
	}

	return 0;
}