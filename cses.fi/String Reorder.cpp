#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n; n = s.size();
	vector<int> count('Z' - 'A' + 1);
	for (auto&i: s)
		++count[i - 'A'];
	if (*max_element(count.begin(), count.end()) * 2 - 1 > n)
	{
		cout << -1 << '\n';
		return 0;
	}

	int prev = -1, mn = 0, tek = n;
	for (int t = 0; t < n; ++t)
	{
		while (!count[mn]) ++mn;
		int mx = max_element(count.begin(), count.end()) - count.begin();
		if (count[mx] * 2 - 1 <= tek - 1)
		{
			int take;
			for (take = mn; (take == prev) || (count[take] == 0); ++take);
			cout << char('A' + take);
			--count[take];
			prev = take;
		}
		else
		{
			cout << char('A' + mx);
			--count[mx];
			prev = mx;
		}
		--tek;
	}
	cout << '\n';

	return 0;
}