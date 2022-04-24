#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<pair<int, int>> t(n);
	for (auto& i : t) cin >> i.first >> i.second;
	sort(t.begin(), t.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	multiset<int> s;
	int res = 0;
	for (int i = 0; i < k; ++i) s.insert(-1);
	for (auto& i : t)
	{
		auto it = s.upper_bound(i.first);
		if (it != s.begin())
		{
			it = prev(it);
			s.erase(it);
			s.insert(i.second);
			++res;
		}
	}
	cout << res << '\n';

	return 0;
}