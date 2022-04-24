#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n >> n;
	multiset<int> a;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		a.insert(h);
	}
	long long res = 0;
	while (a.size() > 1)
	{
		int h = 0;
		h += *a.begin(); a.erase(a.begin());
		h += *a.begin(); a.erase(a.begin());
		a.insert(h);
		res += h;
	}
	cout << res << '\n';

	return 0;
}