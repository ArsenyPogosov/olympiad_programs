#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int l = 0, r = *max_element(a.begin(), a.end()) + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;

		vector<int> ps(n);
		for (int i = 0; i < n; ++i)
			ps[i] = (i > 0 ? ps[i - 1] : 0) + (a[i] >= m ? 1 : -1);
		
		bool good = false;
		int mn = 0;
		for (int i = k - 1; i < n; ++i)
		{
			if (ps[i] - mn > 0)
			{
				good = true;
				break;
			}
			mn = min(mn, ps[i + 1 - k]);
		}

		if (good)
			l = m;
		else
			r = m;
	}

	cout << l << '\n';

	return 0;
}