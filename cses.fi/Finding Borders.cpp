#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> z;
void zfunc(string s)
{
	int n = s.size();
	z.resize(n); z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i)
	{
		z[i] = max(0, min(r - i, z[i - l]));
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
		if (r < i + z[i]) l = i, r = i + z[i];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	zfunc(s);
	for (int i = s.size() - 1; i > 0; --i)
		if (i + z[i] == s.size())
			cout << s.size() - i << ' ';
	cout << '\n';

	return 0;
}