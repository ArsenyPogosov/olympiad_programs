#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	int res = n;
	for (int l = 0, r = 0; l < n; ++l)
	{
		while (r + 1 < n && a[r + 1] < a[l] + n) ++r;
		res = min(res, n - (r - l + 1));
	}

	cout << res << '\n';

	return 0;
}