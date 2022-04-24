#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n);
	for (auto& i : a) cin >> i, --i;
	vector<vector<pair<int, int>>> res(2);
	vector<char> used;
	for (int i = 0; i < 2; ++i)
	{
		used.assign(n, false);
		for (int j = 0; j < n; ++j)
			if (!used[j])
			{
				vector<int> cycle{j};
				for (int it = a[j]; it != j; it = a[it]) cycle.push_back(it);
				for (auto& i : cycle) used[i] = true;
				int m = cycle.size();
				if (m == 1) continue;
				if (m == 2)
				{
					res[i].emplace_back(cycle[0], cycle[1]);
					swap(a[cycle[0]], a[cycle[1]]);
					continue;
				}
				for (int d = 1; d < m - d; ++d)
				{
					res[i].emplace_back(cycle[d], cycle[m - d]);
					swap(a[cycle[d]], a[cycle[m - d]]);
				}
			}
	}

	int t;
	for (t = 0; t < 2 && res[t].size(); ++t);
	cout << t << '\n';
	for (int i = 0; i < t; ++i)
	{
		cout << res[i].size() << '\n';
		for (auto& j : res[i])
			cout << j.first + 1 << ' ' << j.second + 1 << '\n';
	}

	return 0;
}