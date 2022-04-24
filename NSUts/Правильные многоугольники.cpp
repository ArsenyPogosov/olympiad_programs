#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

pair<int, int> fix(pair<int, int> a)
{
	if (a.first < 0 || (a.first == 0 && a.second < 0))
	{
		a.first *= -1;
		a.second *= -1;
	}

	return a;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	map<pair<int, int>, int> mp;

	for (int i = 0; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		++mp[fix({ x, y })];
	}

	long long res = 0;
	for (auto& i : mp)
	{
		auto it = mp.find(fix({ -i.first.second, i.first.first }));
		if (it != mp.end())
			res += (i.second - 1) * 1ll * i.second * 1ll * (it->second - 1) * 1ll * it->second;
	}

	cout << res << '\n';

	return 0;
}