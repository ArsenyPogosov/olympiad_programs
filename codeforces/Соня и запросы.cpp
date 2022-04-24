#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> cnt;

string add(string s)
{
	string res(18 - s.size(), '0');
	res += s;
	return res;
}

string mask(string s)
{
	string res = s;
	for (auto& i : res) i = '0' + ((i - '0') % 2);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char td;
		string s;
		cin >> td >> s; s = add(s);
		if (td == '+')
		{
			++cnt[mask(s)];
		}
		if (td == '-')
		{
			--cnt[mask(s)];
		}
		if (td == '?')
		{
			cout << cnt[s] << '\n';
		}
	}

	return 0;
}