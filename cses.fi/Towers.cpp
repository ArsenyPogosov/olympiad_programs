#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	multiset<int> top;
	for (auto& i : a)
	{
		auto it = top.upper_bound(i);
		if (it != top.end()) top.erase(it);
		top.insert(i);
	}
	cout << top.size() << '\n';

	return 0;
}