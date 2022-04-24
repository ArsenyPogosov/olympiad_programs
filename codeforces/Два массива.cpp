#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 998244353;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	vector<int> targ(m, -1);
	int k = n - 1;
	for (int c = m - 1; c >= 0; --c)
	{
		while (k >= 0 && b[c] != a[k])
		{
			if (a[k] < b[c]) 
			{
				cout << 0 << '\n';
				return 0;
			}
			--k;
		}
		if (k < 0)
		{
			cout << 0 << '\n';
			return 0;
		}
		targ[c] = k;
	}
	if (!is_sorted(targ.begin(), targ.end()) || ((*min_element(a.begin(), a.begin() + targ[0] + 1)) != b[0]))
	{
		cout << 0 << '\n';
		return 0;	
	}
	long long res = 1;
	for (int i = 0; i < m - 1; ++i)
	{
		int l = targ[i], r = targ[i + 1] - 1;
		for (int j = targ[i] + 1; j <= targ[i + 1] - 1; ++j)
		{
			if (a[j] < b[i + 1]) l = j;
			if (a[j] < b[i] && r == targ[i + 1] - 1) r = j - 1;
		}
		res = (res * max(0, r - l + 1)) % p;
		if (res == 0)
		{
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << res << '\n';

	return 0;
}