#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> d(n + 2, 1e9); d[0] = -1e9;
	for (int t = 0; t < n; ++t)
	{
		int i; cin >> i;
		auto it = upper_bound(d.begin(), d.end(), i);
		if (*prev(it) != i)
			*it = i;
	}
	cout << lower_bound(d.begin(), d.end(), 1e9) - d.begin() - 1 << '\n';

	return 0;
}