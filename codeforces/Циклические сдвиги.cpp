#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void count_sort(vector<int> &ind, vector<int> &val)
{
	int n = ind.size(), m = *max_element(val.begin(), val.end()) + 1;
	vector<int> cnt(m), pos(m + 1);
	for (auto& i : val) ++cnt[i];
	partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);
	vector<int> res(n);
	for (auto& i : ind) res[pos[val[i]]++] = i;
	ind = res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int n = s.size();
	int k; cin >> k; --k;

	vector<int> sufmass(n), c(n);
	{
		iota(sufmass.begin(), sufmass.end(), 0);
		for (int i = 0; i < n; ++i)
			c[i] = s[i] - 32;
		count_sort(sufmass, c);
		vector<int> nc(n);
		int was = c[sufmass[0]];
		for (int i = 1; i < n; ++i)
		{
			int now = c[sufmass[i]];
			nc[sufmass[i]] = nc[sufmass[i - 1]] + (was != now);
			was = now;
		}
		c = nc;
	}
	for (int l = 2; l < n * 2; l <<= 1)
	{
		for (auto& i : sufmass) i = (n + i - l / 2) % n;
		count_sort(sufmass, c);
		vector<int> nc(n);
		pair<int, int> was = { c[sufmass[0]], c[(sufmass[0] + l / 2) % n] };
		for (int i = 1; i < n; ++i)
		{
			pair<int, int> now = { c[sufmass[i]], c[(sufmass[i] + l / 2) % n] };
			nc[sufmass[i]] = nc[sufmass[i - 1]] + (was != now);
			was = now;
		}
		c = nc;
	}

	for (auto&i: sufmass)
		if (c[i] == k)
		{
			rotate(s.begin(), s.begin() + i, s.end());
			cout << s << '\n';
			return 0;
		}
	cout << "IMPOSSIBLE\n";

	return 0;
}