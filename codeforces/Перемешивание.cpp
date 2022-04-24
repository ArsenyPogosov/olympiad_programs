#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, x, m; cin >> n >> x >> m;
		vector<pair<int, int>> s; s.emplace_back(x, x);
		for (int j = 0; j < m; ++j)
		{
			int l, r; cin >> l >> r;
			bool can = false;
			vector<pair<int, int>> ns;
			for (int i = 0; i < s.size(); ++i)
			{
				if (max(s[i].first, l) <= min(s[i].second, r))
				{
					can = true;
					l = min(s[i].first, l);
					r = max(s[i].second, r);
				}
				else
					ns.push_back(s[i]);
			}
			if (can)
				ns.emplace_back(l, r);
			s = ns;
		}
		int res = 0;
		for (auto& i : s)
			res += i.second - i.first + 1;
		cout << res << '\n';
	}

	return 0;
}