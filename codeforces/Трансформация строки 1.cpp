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
		string a, b; cin >> a >> b;
		bool good = true;
		vector<vector<int>> cnt(22, vector<int>(22));
		for (int i = 0; i < n; ++i)
		{
			if (a[i] > b[i])
			{
				good = false;
				break;
			}
			if (a[i] != b[i])
				cnt[a[i] - 'a'][b[i] - 'a'] = 1;
		}
		if (!good)
		{
			cout << -1 << '\n';
			continue;
		}
		int res = 0;
		for (int i = 0; i <= 20; ++i)
		{
			int j;
			for (j = 0; j <= 20; ++j)
				if (cnt[i][j] == 1)
					break;
			if (cnt[i][j] == 1)
			{
				++res;
				for (int k = 0; k <= 20; ++k)
					cnt[j][k] |= cnt[i][k];
				cnt[j][j] = 0;
			}
		}
		cout << res << '\n';
	}

	return 0;
}