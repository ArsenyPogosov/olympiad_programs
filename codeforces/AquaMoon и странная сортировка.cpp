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
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		vector<int> aa = a;
		sort(aa.begin(), aa.end());
		vector<vector<int>> help(1e5 + 1, vector<int>(2));
		for (int i = 0; i < n; ++i)
			++help[aa[i]][i % 2];

		bool good = true;
		for (int i = 0; i < n; ++i)
		{
			if (help[a[i]][i % 2] <= 0)
				good = false;
			--help[a[i]][i % 2];
		}

		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}