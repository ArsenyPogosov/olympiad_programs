#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m), pos(m), ans(m);
	for (auto& i : a) cin >> i;
	for (auto& i : b) {	cin >> i; --i; }
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int x, int y) { return b[x] > b[y]; });
	unordered_map<int, int> cnt;
	int tek = n - 1, res = 0;
	for (auto& i : pos)
	{
		for (; tek >= b[i]; --tek)
		{
			++cnt[a[tek]];
			if (cnt[a[tek]] == 1)
				++res;

		}
		ans[i] = res;
	}
	for (auto& i : ans) cout << i << '\n';

	return 0;
}