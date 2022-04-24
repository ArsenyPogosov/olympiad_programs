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
	vector<int> sz = z; sort(sz.begin(), sz.end());
	int count = 0; vector<pair<int, int>> res; res.reserve(n);
	for (int i = 1; i <= n; ++i)
		if (z[n - i] == i)
		{
			++count;
			res.push_back({ i, sz.end() - lower_bound(sz.begin(), sz.end(), i) });
		}
	cout << count << '\n';
	for (auto& i : res) cout << i.first << ' ' << i.second << '\n';

	return 0;
}