#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int res = 0, len = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == s[i - 1])
			++len;
		else
		{
			res = max(res, len);
			len = 1;
		}
	}
	res = max(res, len);
	cout << res << '\n';

	return 0;
}