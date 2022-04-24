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

int n;
string s;
vector<int> p, c, d;

vector<int> DO;

int merge(int a, int b)
{
	if (DO[a] <= DO[b]) 
		return a;
	return b;
}

void build(int v, int l, int r)
{
	if (l == r)
	{
		DO[v] = l;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	DO[v] = merge(DO[v * 2 + 1], DO[v * 2 + 2]);
}

void count_sort(vector<int>& a, vector<int>& b)
{
	vector<int> cnt(max(127 - 33 + 5, n)), pos(max(127 - 33 + 5, n) + 1);
	for (auto& i : a) ++cnt[b[i]];
	partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);
	vector<int> na(n);
	for (auto& i : a) na[pos[b[i]]++] = i;
	a = na;
}

int main()
{
	cin >> s; s += char(30); n = s.size();
	p.resize(n); c.resize(n); d.resize(n);
	{
		iota(p.begin(), p.end(), 0);
		for (int i = 0; i < n - 1; ++i) c[i] = s[i] - 33 + 1; c[n - 1] = 0;
		count_sort(p, c);
		vector<int> nc(n);
		int bef = c[p[0]];
		for (int i = 1; i < n; ++i)
		{
			int now = c[p[i]];
			nc[p[i]] = nc[p[i - 1]] + (bef != now);
			bef = now;
		}
		c = nc;
	}
	int k = 0;
	while ((1 << k) < n && (c[p[n - 1]] < n - 1))
	{
		for (auto& i : p) i = ((i - (1 << k)) % n + n) % n;
		count_sort(p, c);
		vector<int> nc(n);
		pair<int, int> bef = { c[p[0]], c[(p[0] + (1 << k)) % n] };
		for (int i = 1; i < n; ++i)
		{
			pair<int, int> now = { c[p[i]], c[(p[i] + (1 << k)) % n] };
			nc[p[i]] = nc[p[i - 1]] + (bef != now);
			bef = now;
		}
		c = nc;
		++k;
	}
	k = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		while (s[p[c[i]] + k] == s[p[c[i] - 1] + k]) ++k;
		d[c[i]] = k;
		k = max(0, k - 1);
	}

	DO.resize(n * 4 + 5);
	build(0, 0, n - 1);

	return 0;
}