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

int m;
vector<vector<int>> st;
vector<int> Log2(1e5 * 5 + 1);

void buildLog2()
{
	for (int i = 0; (1 << i) <= 1e5 * 5; ++i)
		for (int j = (1 << i); j < (1 << i) * 2 && j <= 1e5 * 5; ++j)
			Log2[j] = i;
}

void buildST()
{
	buildLog2();
	m = Log2[n] + 4;
	st.resize(m, vector<int>(n));
	st[0] = d;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			st[i][j] = min(st[i - 1][j], st[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

int dist(int l, int r)
{
	if (l == r) return n - l;
	l = c[l]; r = c[r];
	if (l > r) swap(l, r);
	int i = Log2[r - l];
	return min(st[i][l + 1], st[i][r - (1 << i) + 1]);
}

void count_sort(vector<int>& a, vector<int>& b)
{
	vector<int> cnt(max(127-33+5, n)), pos(max(127-33+5, n) + 1);
	for (auto& i : a) ++cnt[b[i]]; 
	partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);
	vector<int> na(n);
	for (auto& i : a) na[pos[b[i]]++] = i;
	a = na;
}

bool comp(pair<int, int> seg1, pair<int, int> seg2)
{
	int d1 = seg1.second - seg1.first + 1, d2 = seg2.second - seg2.first + 1, di = dist(seg1.first, seg2.first);
	if (d1 == d2 && di >= d1) return seg1 < seg2;
	if (di >= min(d1, d2)) return d1 < d2;
	return c[seg1.first] < c[seg2.first];
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
	buildST();
	int q; cin >> q;
	vector<pair<int, int>> Q(q);
	for (auto& i : Q)
	{
		cin >> i.first >> i.second;
		--i.first; --i.second;
	}
	sort(Q.begin(), Q.end(), comp);
	for (auto& i : Q)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	return 0;
}