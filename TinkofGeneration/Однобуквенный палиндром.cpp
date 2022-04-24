#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int MAXC = 65535 + 1;
	int n; cin >> n;
	vector<int> a(n);
	vector<set<int>> pos(MAXC);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		pos[a[i]].insert(i);
	}

	if (n % 2)
	{
		cout << "0\n";
		return 0;
	}

	int res = 1e9;
	for (int i = 0; i < n; ++i)
	{
		int j = n - 1 - i;
		pos[a[i]].erase(i);
		auto it = pos[a[i]].lower_bound(j);
		if (it != pos[a[i]].end())
			res = min(res, *it - j);
		if (it != pos[a[i]].begin())
			res = min(res, j - *prev(it));
		pos[a[i]].insert(i);
	}

	cout << res << '\n';

	return 0;
}