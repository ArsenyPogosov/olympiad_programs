#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) cin >> i;

	long long res = 0, cnt = 0;
	map<int, int> c;

	auto add = [&](int x)
	{
		if (!c[x]++)
			++cnt;
	};
	auto del = [&](int x)
	{
		if (!--c[x])
			--cnt;
	};

	for (int l = 0, r = 0; l < n; del(a[l++]))
	{
		while (cnt <= k && r < n)
			add(a[r++]);
		res += r - l - (cnt > k);
	}

	cout << res << '\n';

	return 0;
}