#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	set<int> t;
	int l = 0, r = 0, res = 0;
	while (r < n)
	{
		if (t.find(a[r]) == t.end())
		{
			t.insert(a[r++]);
			res = max(res, r - l);
			continue;
		}
		while (a[l] != a[r]) t.erase(t.find(a[l++]));
		l++; r++;
	}
	cout << res << '\n';

	return 0;
}