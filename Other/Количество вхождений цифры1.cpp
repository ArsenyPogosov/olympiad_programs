#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string S9 = "WXYZ01234";
string S27 = "NOPQRSTUVWXYZ0123456789ABCD";

int s9(char h)
{
	return S9.find(h) - S9.find('0');
}

int s27(char h)
{
	return S27.find(h) - S27.find('0');
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	char h; cin >> h;
	string s; cin >> s;

	int ittt = 0;
	while (ittt < s.size() && s[ittt] == '0')
		++ittt;
	s = s.substr(ittt, 1e9);

	if (s == "")
	{
		if (h == '0')
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

		return 0;
	}

	map<int, string> s9from10;

	for (auto&i: S9)
		for (auto& j : S9)
			for (auto& k : S9)
			{
				s9from10[s9(i) * 9 * 9 + s9(j) * 9 + s9(k)] = i;
				s9from10[s9(i) * 9 * 9 + s9(j) * 9 + s9(k)] += j;
				s9from10[s9(i) * 9 * 9 + s9(j) * 9 + s9(k)] += k;
			}

	int cnt = 0;
	if (s.size() % 2)
		s = '0' + s;
	for (int i = 0; i < s.size(); i += 2)
	{
		int rs = s27(s[i]) * 27 + s27(s[i + 1]);
		string ss = s9from10[rs];

		int it = 0;
		while (i == 0 && h == '0' && it < ss.size() && ss[it] == '0')
			--cnt, ++it;

		for (auto& i : ss)
			if (i == h)
				++cnt;
	}

	cout << cnt << '\n';

	return 0;
}