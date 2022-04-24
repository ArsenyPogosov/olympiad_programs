#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> ord(n);
	for (int i = 0; i < n; ++i)
		cin >> ord[i].first, ord[i].second = i;
	sort(ord.begin(), ord.end());
	int prev = -1, c = -1;
	for (auto& i : ord)
	{
		if (prev != i.first)
		{
			prev = i.first; ++c;
		}
		a[i.second] = c;
	}
	int k = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j])
				++k;
	vector<pair<int, int>> res;
	vector<set<int>> pos(c + 1);
	for (int i = 0; i < n; ++i) pos[a[i]].insert(i);
	while (res.size() < k)
	{
		for (int i = c; i > 0; --i)
		{
			while (true)
			{
				if (*pos[i].begin() > *(--(pos[i - 1].end()))) break;
				auto lf = pos[i].begin();
				auto rf = --pos[i].lower_bound(*(--(pos[i - 1].end())));
				auto ls = pos[i - 1].upper_bound(*lf);
				auto rs = --(pos[i - 1].end());
				res.emplace_back(*lf, *rs);
				for (auto j = ls; j != rs; ++j)
					res.emplace_back(*lf, *j);
				for (auto j = rf; j != lf; --j)
					res.emplace_back(*j, *rs);
				int x = *lf, y = *rs;
				pos[i].erase(x); pos[i].insert(y);
				pos[i - 1].erase(y); pos[i - 1].insert(x);
			}
		}
	}
	cout << res.size() << '\n';
	for (auto& i : res) cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}