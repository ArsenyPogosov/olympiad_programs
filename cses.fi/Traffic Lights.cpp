#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, n; cin >> x >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	set<int> s; s.insert(0); s.insert(x);
	multiset<int> res; res.insert(x);
	for (auto& i : a)
	{
		auto r = s.upper_bound(i), l = prev(r);
		res.erase(res.find(*r - *l));
		res.insert(i - *l);
		res.insert(*r - i);
		s.insert(i);
		cout << *prev(res.end()) << ' ';
	}
	cout << '\n';

	return 0;
}