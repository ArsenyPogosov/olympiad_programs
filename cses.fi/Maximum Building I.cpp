#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;

int res(vector<int>& a)
{
	vector<int> ord(n); 
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) {return a[x] > a[y]; });
	int mx = 0, res = 0;
	vector<int> sz(n, 0);
	for (auto& i : ord)
	{
		int l = i, r = i;
		if (i > 0) l -= sz[i - 1];
		if (i < n - 1) r += sz[i + 1];
		sz[l] = sz[r] = r - l + 1;
		mx = max(mx, r - l + 1);
		res = max(res, mx * a[i]);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	int ans = 0;
	vector<int>tek(n);
	for (int i = 0; i < m; ++i)
	{
		for (auto& j : tek)
		{
			char h; cin >> h;
			j = (h == '*' ? 0 : j + 1);
		}
		ans = max(ans, res(tek));
	}
	cout << ans << '\n';

	return 0;
}