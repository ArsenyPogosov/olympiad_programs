#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int n = s.size();

	int l = -1, r = n;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		bool result = false;
		string a = s.substr(0, m), b = s.substr(m, n - m);

		if (m < n - m)
			a = string("0", n - m - m) + a;
		else
			b = string("0", m - (n - m)) + b;
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] == b[i]) continue;
			if (a[i] < b[i])
				l = m;
			if (a[i] > b[i])
				r = m;
			result = true;
			break;
		}
		if (result) continue;
		l = m;
	}
	int res = l;
	for (int i = 0; i < l; ++i)
		if (s[i + 1] == '0')
			--res;
	cout << res << '\n';

	return 0;
}