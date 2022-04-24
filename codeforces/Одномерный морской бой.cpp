#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, k, a;

int sm(int s)
{
	return (s / (a + 1)) + (s % (a + 1) == a);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> a;
	int count = sm(n), m; cin >> m;
	set<int> shoot;
	for (int i = 0; i < m; ++i)
	{
		int x; cin >> x; --x;
		auto it = shoot.lower_bound(x);
		if (it != shoot.end() && *it == x) continue;
		int l = -1, r = n;
		if (it != shoot.begin()) l = *prev(it);
		if (it != shoot.end()) r = *it;
		shoot.insert(x);
		count += sm(x - l - 1) + sm(r - x - 1) - sm(r - l - 1);
		if (count < k)
		{
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';

	return 0;
}