#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool check(string& s, int i, string t)
{
	int n = t.size();
	if (i + n - 1 >= s.size()) return false;

	for (int j = 0; j < n; ++j)
		if (t[j] != '?' && t[j] != s[i + j])
			return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string t; cin >> t;

	string s;
	for (int i = 1; i <= 1e6; ++i)
		s += to_string(i);

	for (int i = 0;; ++i)
		if (check(s, i, t))
		{
			cout << i + 1 << ' ' << i + t.size() << '\n';
			break;
		}

	return 0;
}