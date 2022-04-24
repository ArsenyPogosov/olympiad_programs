#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	long long n = s.size();

	vector<long long> pref(n), pw(n), suf(n);
	for (long long i = 1; i < n; ++i)
		pref[i] = pref[i - 1] * 10 + (s[i - 1] - '0');
	pref[0] = 0;

	pw[0] = 1;
	for (long long i = 1; i < n; ++i) pw[i] = pw[i - 1] * 10;

	for (long long i = n - 2, pw = 1; i >= 0; --i, pw *= 10)
		suf[i] = suf[i + 1] + pw * (s[i + 1] - '0');
	suf[n - 1] = 0;

	vector<long long> res(10);
	for (long long k = 0; k < 10; ++k)
		for (long long i = 0; i < n; ++i)
		{
			if (k != 0)
				res[k] += pref[i] * pw[n - i - 1];
			else
			{
				res[k] += max(0ll, pref[i] - 1) * pw[n - i - 1];
			}
			if (k != 0 || pref[i] > 0)
			{
				if (k < s[i] - '0') res[k] += pw[n - i - 1];
				if (k == s[i] - '0') res[k] += suf[i] + 1;
			}
		}

	for (auto& i : res) cout << i << ' ';
	cout << '\n';

	return 0;
}