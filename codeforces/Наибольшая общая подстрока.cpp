//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

void count_sort(vector<int>& a, vector<int>& b)
{
	int n = a.size();
	vector<int> cnt(max(n, 30)), pos(max(n, 30) + 1);
	for (auto& i : a) ++cnt[b[i]];
	partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);
	vector<int> na(n);
	for (auto& i : a) na[pos[b[i]]++] = i;
	a = na;
}

int main()
{
	string s1, s2, s; cin >> s1 >> s2; s = (s1 + '#' + s2 + '$');
	int n = s1.size() + 1 + s2.size() + 1;
	vector<int> p(n), c(n);
	{
		iota(p.begin(), p.end(), 0);
		for (int i = 0; i < s1.size(); ++i) c[i] = s1[i] - 'a' + 2;
		c[s1.size()] = 1;
		for (int i = 0; i < s2.size(); ++i) c[i + s1.size() + 1] = s2[i] - 'a' + 2;
		c[n - 1] = 0;
		count_sort(p, c);
		vector<int> nc(n);
		int pref = c[p[0]];
		for (int i = 1; i < n; ++i)
		{
			int now = c[p[i]];
			nc[p[i]] = nc[p[i - 1]] + (pref != now);
			pref = now;
		}
		c = nc;
	}
	int k = 0;
	while ((1 << k) < n && c[p[n - 1]] < n - 1)
	{
		for (auto& i : p) i = (i - (1 << k) + n) % n;
		count_sort(p, c);
		vector<int> nc(n);
		pair<int, int> pref = { c[p[0]], c[(p[0] + (1 << k)) % n] };
		for (int i = 1; i < n; ++i)
		{
			pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
			nc[p[i]] = nc[p[i - 1]] + (pref != now);
			pref = now;
		}
		c = nc;
		++k;
	}
	vector<int> lcp(n - 1);
	k = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int pi = c[i], j = p[pi - 1];
		while (s[i + k] == s[j + k]) ++k;
		lcp[pi - 1] = k;
		k = max(0, k - 1);
	}
	int res = 0, pos = 0;
	for (int i = 0; i < n - 1; ++i)
		if ((min(p[i], p[i + 1]) < s1.size()) && (max(p[i], p[i + 1]) > s1.size()))
			if (res < lcp[i])
			{
				res = lcp[i];
				pos = min(p[i], p[i + 1]);
			}
	cout << s1.substr(pos, res) << '\n';

	return 0;
}