#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int C = 'z' - 'a' + 1;

void count_sort(vector<int> &ind, vector<int> &val)
{
	vector<int> cnt(max(C + 1, (int)ind.size())), pos(max(C + 1, (int)ind.size()) + 1);
	for (auto& i : val)
		++cnt[i];
	partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);

	vector<int> res(ind.size());
	for (auto& i : ind)
		res[pos[val[i]]++] = i;
	ind = res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s; s += '$';
	int n = s.size();

	vector<int> sufmass(n), c(n);
	{
		iota(sufmass.begin(), sufmass.end(), 0);
		for (int i = 0; i < n - 1; ++i)
			c[i] = s[i] - 'a' + 1;
		c[n - 1] = 0;
		count_sort(sufmass, c);
		vector<int> nc(n);
		int was = c[sufmass[0]];
		for (int j = 1; j < n; ++j)
		{
			int tek = c[sufmass[j]];
			nc[sufmass[j]] = nc[sufmass[j - 1]] + (was != tek);
			was = tek;
		}
		c = nc;
	}
	for (int i = 2; i < n * 2; i <<= 1)
	{
		for (auto& j : sufmass)
			j = (n + j - i / 2) % n;
		count_sort(sufmass, c);
		vector<int> nc(n);
		pair<int, int> was = { c[sufmass[0]], c[(sufmass[0] + i / 2) % n] };
		for (int j = 1; j < n; ++j)
		{
			pair<int, int> tek = { c[sufmass[j]], c[(sufmass[j] + i / 2) % n] };
			nc[sufmass[j]] = nc[sufmass[j - 1]] + (was != tek);
			was = tek;
		}
		c = nc;
	}

	for (int i = 1; i < n; ++i)
		cout << sufmass[i] + 1 << ' ';
	cout << '\n';

	return 0;
}