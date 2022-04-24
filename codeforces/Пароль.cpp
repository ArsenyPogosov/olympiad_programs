#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> z;
void zfunc(string s)
{
	int n = s.size(), l = 0, r = 0;
	z.assign(n, 0); z[0] = n;
	for (int i = 1; i < n; ++i)
	{
		z[i] = max(0, min(z[i - l], r - i));
		for (; i + z[i] < n && s[i + z[i]] == s[z[i]]; ++z[i]);
		if (i + z[i] > r) { r = i + z[i]; l = i; }
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s; int n = s.size(); zfunc(s);
	int res = 0;
	bool t = false;
	for (int i = 1; i < n; ++i)
	{
		if (res >= z[i] && z[i] == n - i)
		{
			t = true;
			res = z[i];
			break;
		}
		res = max(res, min(z[i], n - i - 1));
	}
	if (res > 0 && t)
		cout << s.substr(0, res) << '\n';
	else
		cout << "Just a legend\n";

	return 0;
}