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

string s;
vector<int> p;

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

int Count(string& h)
{
	int n = s.size(), m = h.size();
	int L, R;
	{
		int l = -1, r = n;
		while (l + 1 < r)
		{
			int mid = (l + r) / 2;
			string tek = s.substr(p[mid], m);
			if (tek < h)
				l = mid;
			else
				r = mid;
		}
		if (r == n) return 0;
		if (s.substr(p[r], m) != h) return 0;
		L = r;
	}
	{
		int l = -1, r = n;
		while (l + 1 < r)
		{
			int mid = (l + r) / 2;
			string tek = s.substr(p[mid], m);
			if (tek <= h)
				l = mid;
			else
				r = mid;
		}
		if (l == -1) return 0;
		if (s.substr(p[l], m) != h) return 0;
		R = l;
	}
	return R - L + 1;
}

int main()
{
	cin >> s; s += "$";
	int n = s.size();

	p.resize(n); vector<int> c(n);
	{
		iota(p.begin(), p.end(), 0);
		for (int i = 0; i < n - 1; ++i) c[i] = s[i] - 'a' + 1; c[n - 1] = 0;
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

	int m; cin >> m;
	while (m--)
	{
		string h; cin >> h;
		cout << Count(h) << '\n';
	}

	return 0;
}