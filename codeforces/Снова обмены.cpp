#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (auto& i : a) cin >> i;
		for (auto& i : b) cin >> i;
		map<pair<int, int>, int> x;
		for (int i = 0; i < (n + 1) / 2; ++i)
			++x[{min(b[i], b[n - 1 - i]), max(b[i], b[n - 1 - i])}];
		bool bad = false;
		for (int i = 0; i < (n + 1) / 2; ++i)
		{
			auto it = x.find({ min(a[i], a[n - 1 - i]), max(a[i], a[n - 1 - i]) });
			if (it == x.end() || it->second <= 0)
			{
				bad = true;
				break;
			}

			--it->second;
		}
		if (bad)
			cout << "No\n";
		else
			cout << "Yes\n";
	}

	return 0;
}