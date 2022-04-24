#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m = 21; cin >> n;
	vector<int> c(m, 0);
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		int t = 0;
		while (h > 0)
		{
			c[t] += (h % 2);
			h /= 2;
			++t;
		}
	}
	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		long long tek = 0;
		for (int i = 0; i < m; ++i)
			if (c[i])
			{
				--c[i];
				tek += (1 << i);
			}
		res += tek * tek;
	}
	cout << res << '\n';

	return 0;
}