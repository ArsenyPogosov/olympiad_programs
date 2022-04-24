#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<long long> a(n), ps(n);
	for (auto& i : a) cin >> i;
	partial_sum(a.begin(), a.end(), ps.begin());
	while (q--)
	{
		int l, r; cin >> l >> r; --l; --r;
		cout << ps[r] - (l > 0 ? ps[l - 1] : 0) << '\n';
	}

	return 0;
}