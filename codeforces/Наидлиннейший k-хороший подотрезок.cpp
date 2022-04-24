#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	unordered_map<int, int> cnt;
	int l = 0, r = 0, nw = 0, bl = 0, br = 1;
	while (l < n)
	{
		while (r < n && nw <= k)
			if (!(cnt[a[r++]]++))
				++nw;
		if (nw > k)
		{
			--cnt[a[--r]];
			--nw;
		}
		if (r - l > br - bl) { bl = l; br = r; }
		if (!(--cnt[a[l++]]))
			--nw;
	}
	cout << bl + 1 << ' ' << br << '\n';

	return 0;
}