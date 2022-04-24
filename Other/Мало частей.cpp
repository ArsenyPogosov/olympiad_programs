#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int res = 0, tcnt = 0;
	vector<char> cnt('z' - 'a' + 1);
	for (int i = 0; i < n;)
	{
		for (int len = 1; i < n && len <= k; ++i, ++len)
		{
			if (!cnt[s[i] - 'a'])
				++tcnt;

			cnt[s[i] - 'a'] = 1;

			if (tcnt > 3) break;
		}
		++res;
		cnt.assign('z' - 'a' + 1, 0);
		tcnt = 0;
	}

	cout << res << '\n';

	return 0;
}