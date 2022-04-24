#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> t(n);
	for (auto& i : t) cin >> i.first >> i.second;
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b) { return t[a] < t[b]; });
	int mx = 0;
	vector<int> res(n);
	set<pair<int, int>> s;
	for (auto& i : ord)
	{
		auto it = s.lower_bound({ t[i].first, 0 });
		if (it != s.begin())
		{
			it = prev(it);
			int num = it->second;
			s.erase(it);
			s.insert({ t[i].second, num });
			res[i] = num;
		}
		else
		{
			int num = s.size() + 1;
			mx = max(mx, num);
			s.insert({ t[i].second, num });
			res[i] = num;
		}
	}
	cout << mx << '\n';
	for (auto& i : res) cout << i << ' ';
	cout << '\n';

	return 0;
}