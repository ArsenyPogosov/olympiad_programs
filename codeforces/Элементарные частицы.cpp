#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int m = 150001;

int main()
{
	int t; cin >> t;
	vector<int> cnt(m);
	vector<int> used(m, -1);
	while (t--)
	{
		int n; cin >> n;
		int mn = n + 1;
		for (int i = 0; i < n; ++i)
		{
			int a; cin >> a; --a;
			if (used[a] == t)
				mn = min(mn, i - cnt[a]);
			cnt[a] = i;
			used[a] = t;
		}

		cout << max(-1, n - mn) << '\n';
	}

	return 0;
}