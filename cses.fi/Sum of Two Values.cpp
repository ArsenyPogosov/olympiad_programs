#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first; a[i].second = i;
	}
	sort(a.begin(), a.end());
	int j = n - 1;
	for (int i = 0; i < j; ++i)
	{
		while (i < j && a[i].first + a[j].first > x) --j;
		if (i < j && a[i].first + a[j].first == x)
		{
			cout << a[i].second + 1 << ' ' << a[j].second + 1 << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";

	return 0;
}