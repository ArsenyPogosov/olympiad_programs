#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector<int> a(n);
	int bl = 0, br = 0;
	int l = 0, r = 0; a[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		a[i] = max(1, min(a[l + (r - i)], r - i + 1));
		while (i - a[i] >= 0 && i + a[i] < n && s[i - a[i]] == s[i + a[i]]) ++a[i];
		if (r < i + a[i] - 1)
		{
			l = i - a[i] + 1;
			r = i + a[i] - 1;
		}
		if (br - bl < r - l)
		{
			bl = l;
			br = r;
		}
	}
	l = 0, r = 0;
	for (double i = 0.5; i < n; ++i)
	{
		a[i] = max(0, min(a[int(l + (r - i) - 0.5)], int(r - i + 0.5)));
		while (i - a[i] + 0.5 - 1 >= 0 && i + a[i] - 0.5 + 1< n && s[int(i - a[i] + 0.5 - 1)] == s[int(i + a[i] - 0.5 + 1)]) ++a[i];
		if (r < i + a[i] - 1)
		{
			l = i - a[i] + 0.5;
			r = i + a[i] - 0.5;
		}
		if (br - bl < r - l)
		{
			bl = l;
			br = r;
		}
	}
	cout << s.substr(bl, br - bl + 1) << '\n';

	return 0;
}