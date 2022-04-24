#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void count_sort(vector<int>& p, vector<int>& c)
{
	int n = p.size(), m = max(n, 'z' - 'a' + 1);
	vector<int> cnt(m), pos(m + 1);
	for (auto& i : p) ++cnt[c[i]];
	partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);
	vector<int> np(n);
	for (auto& i : p) np[pos[c[i]]++] = i;
	p = np;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();

	vector<int> p(n), c(n);
	iota(p.begin(), p.end(), 0);
	for (int i = 0; i < n; ++i) c[i] = s[i] - 'a';
	count_sort(p, c);
	for (int k = 0; (1 << k) < n && c[p[n - 1]] < max('z' - 'a' + 2, n - 1); ++k)
	{
		for (auto& i : p) i = (i - (1 << k) + n) % n;
		count_sort(p, c);
		pair<int, int> was = { c[p[0]], c[(p[0] + (1 << k)) % n] }; c[p[0]] = 0;
		for (int i = 1; i < n; ++i)
		{
			pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
			c[p[i]] = c[p[i - 1]] + (was < now);
			was = now;
		}
	}
	cout << (s + s).substr(p[0], n) << '\n';

	return 0;
}