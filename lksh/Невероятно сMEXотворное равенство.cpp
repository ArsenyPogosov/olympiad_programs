#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 998244353;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		vector<char> have(n + 2);
		for (auto& i : a)
		{
			cin >> i;
			have[i] = true;
		}

		int x = 0; for (; have[x]; ++x);
		vector<int> need(x, 0), minend(n, -1);
		int l = 0, r = 0, c = 0;
		while (l < n)
		{
			while ((c < x || r <= l) && r < n)
			{
				if (a[r] < x)
				{
					if (!need[a[r]]) ++c;
					++need[a[r]];
				}
				++r;
			}
			if (c < x || r <= l) break;
			minend[l] = r;
			if (a[l] < x)
			{
				if (need[a[l]] == 1) --c;
				--need[a[l]];
			}
			++l;
		}

		vector<int> sufsum(n + 1); sufsum[n] = 1;
		for (int i = n - 1; i >= 0; --i)
		{
			int res = (minend[i] != -1 ? sufsum[minend[i]] : 0);
			sufsum[i] = (res + sufsum[i + 1]) % p;
			if (i == 0)
				cout << res << '\n';
		}
	}

	return 0;
}