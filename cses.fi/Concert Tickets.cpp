#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	multiset<int> a;
	for (int i = 0; i < n; ++i) { int h; cin >> h; a.insert(h); }
	for (int i = 0; i < m; ++i)
	{
		int h; cin >> h;
		auto it = a.upper_bound(h);
		if (it == a.begin())
			cout << "-1\n";
		else
		{
			it = prev(it);
			cout << *it << '\n';
			a.erase(it);
		}
	}

	return 0;
}