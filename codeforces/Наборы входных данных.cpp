#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> count(k);
	for (int i = 0; i < n; ++i)
	{
		int m; cin >> m;
		++count[m - 1];
	}
	set<pair<int, int>> have;
	for (int i = 0; i < k; ++i)
		if (count[i])
			have.insert({ -i, count[i] });
	vector<int> c(k);
	for (auto& i : c) cin >> i;
	vector<int> w(k);
	{
		int nw = -1; w[0] = nw;
		for (int i = 1; i < k; ++i)
		{
			if (c[i - 1] > c[i])
				nw = i - 1;
			w[i] = nw;
		}
	}
	vector<vector<int>> ans;
	while (have.size())
	{
		vector<int> tek;
		int fg = -(have.begin()->first);
		while (fg != -1)
		{
			auto nw = have.lower_bound({ -fg, 0 });
			if (nw == have.end()) break;
			int d = min(c[-nw->first] - int(tek.size()), nw->second);
			if (d == c[-nw->first] - int(tek.size()))
				fg = w[-nw->first];
			else
				--fg;
			for (int i = 0; i < d; ++i) tek.push_back(-nw->first + 1);
			pair<int, int> tadd = *nw; tadd.second -= d;
			have.erase(nw); 
			if (tadd.second)
				have.insert(tadd);

		}
		ans.push_back(tek);
	}
	/*for (int i = k - 1; i >= 0; --i)
	{
		for (int j = 0; j < ans.size() && count[i]; ++j)
		{
			int d = min(c[i] - int(ans[j].size()), count[i]);
			count[i] -= d;
			for (int t = 0; t < d; ++t) ans[j].push_back(i + 1);
		}
		while (count[i])
		{
			int j = ans.size(); ans.push_back({});
			int d = min(c[i] - int(ans[j].size()), count[i]);
			count[i] -= d;
			for (int t = 0; t < d; ++t) ans[j].push_back(i + 1);
		}
	}*/
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i.size();
		for (auto& j : i) cout << ' ' << j;
		cout << '\n';
	}

	return 0;
}