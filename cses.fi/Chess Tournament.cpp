#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	set<pair<int, int>, greater<pair<int, int>>> a;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		a.emplace(h, i);
	}
	vector<pair<int, int>> res;
	while(a.size())
	{
		auto i = *a.begin(); a.erase(a.begin());
		vector<pair<int, int>> toadd;
		while (a.size())
		{
			if (i.first == 0) break;
			auto j = *a.begin();
			if (j.first == 0)
			{
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			res.emplace_back(i.second + 1, j.second + 1);
			--i.first;
			--j.first;
			a.erase(a.begin()); toadd.push_back(j);
		}
		if (i.first > 0)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		for (auto& i : toadd)
			a.insert(i);
	}
	cout << res.size() << '\n';
	for (auto& i : res) cout << i.first << ' ' << i.second << '\n';

	return 0;
}