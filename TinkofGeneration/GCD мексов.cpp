#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		cnt[i + 1] = cnt[i] + (h > 1 ? 1 : 0);
	}

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << (cnt[r] - cnt[l - 1] ? 1 : 2) << '\n';
	}

	return 0;
}