#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int d; cin >> d;

	string alp16 = "0123456789ABCDEF";
	string alp8 = "01234567";

	int n; cin >> n;
	string s;

	for (int i = 0; i < n; ++i)
	{
		char h; cin >> h;
		int x = lower_bound(alp16.begin(), alp16.end(), h) - alp16.begin();
		s += char('0' + ((x >> 3) & 1));
		s += char('0' + ((x >> 2) & 1));
		s += char('0' + ((x >> 1) & 1));
		s += char('0' + ((x >> 0) & 1));
	}

	s = string(((-n * 4) % 3 + 3) % 3, '0') + s;
	string ns;
	for (int i = 0; i < s.size(); i += 3)
		ns += alp8[((s[i] - '0') << 2) + ((s[i + 1] - '0') << 1) + ((s[i + 2] - '0') << 0)];
	s = ns;

	int from = 0;
	for (; from < s.size() && s[from] == '0'; ++from);
	s = s.substr(from);
	if (s == "") s = "0";

	int cnt = 0;
	for (auto& i : s)
		if (i == alp8[d])
			++cnt;
	cout << cnt << '\n';

	return 0;
}