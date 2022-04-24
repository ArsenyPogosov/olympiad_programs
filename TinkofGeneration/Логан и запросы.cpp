#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;

	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	vector<int> b(n + 1);
	for (int i = 0; i < q; ++i)
	{
		int x, y; cin >> x >> y; --x; --y;
		++b[x]; --b[y + 1];
	}
	b.pop_back();
	partial_sum(b.begin(), b.end(), b.begin());

	sort(b.begin(), b.end());

	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i] * 1ll * b[i];

	cout << sum << '\n';

	return 0;
}