#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int ans(string a)
{
	int n = a.size();
	if (n == 1) return atoi(a.c_str());

	reverse(a.begin(), a.end());
	
	int res = 9;
	for (int i = 0; i < 10; ++i)
		for (int d = 0; d < 10; ++d)
			for (int j = 0, tek = i, reg = 0; j < n; ++j, tek = (tek + d) % 10)
			{
				if (tek > a[j] - '0')  reg = 1;
				if (tek < a[j] - '0') reg = -1;

				if (j == n - 1 && reg == 1) break;
				if (j > 0 && tek != 0)
					++res;
			}

	return res;
}

bool good(string &a)
{
	if (a.size() < 3) return true;

	int d = (a[0] - a[1] + 10) % 10;
	for (int i = 1; i < a.size() - 1; ++i)
		if ((a[i] - a[i + 1] + 10) % 10 != d)
			return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string l, r; cin >> l >> r;

	//cout << ans("12") << '\n';
	cout << ans(r) - ans(l) + good(l);

	return 0;
}