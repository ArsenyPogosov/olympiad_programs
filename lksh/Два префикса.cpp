#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	vector<int> ord;
	node() {};
};

int n;
string s;

vector<int> z;
vector<node> tree;

void zfunc()
{
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i)
	{
		z[i] = max(0, min(r - i, z[i - l]));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}
}

void fix(int v)
{
	merge(tree[v * 2 + 1].ord.begin(), tree[v * 2 + 1].ord.end(),
		  tree[v * 2 + 2].ord.begin(), tree[v * 2 + 2].ord.end(),
		  tree[v].ord.begin());
}

void build(int v, int l, int r)
{
	tree[v].ord.resize(r - l);
	if (l + 1 == r)
	{
		tree[v].ord[0] = l + z[l] - 1;
		return;
	}

	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

bool have(int v, int mn, int mx)
{
	auto it = lower_bound(tree[v].ord.begin(), tree[v].ord.end(), mn);
	if ((it != tree[v].ord.end()) && ((*it) <= mx)) 
		return true;

	return false;
}

int query(int v, int l, int r, int mn, int mx)
{
	if (!have(v, mn, mx)) return n;
	if (l + 1 == r) return l;

	int m = (l + r) / 2;
	int res = query(v * 2 + 1, l, m, mn, mx);
	if (res < n) return res;
	return query(v * 2 + 2, m, r, mn, mx);
}

int query(int v, int l, int r, int L, int R, int mn, int mx)
{
	if (r <= L || R <= l) return n;
	if (L <= l && r <= R) return query(v, l, r, mn, mx);

	int m = (l + r) / 2;
	int res = query(v * 2 + 1, l, m, L, R, mn, mx);
	if (res < n) return res;
	return query(v * 2 + 2, m, r, L, R, mn, mx);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size();

	int h = 1;
	while (h < n) h <<= 1;
	z.resize(n); tree.resize(h * 2);
	zfunc(); build(0, 0, n);
	int best = 0;
	for (int i = 2; i < n; ++i)
		best = max(best, i + z[i] - 1 - query(0, 0, n, 1, i, i - 1, n) + 1);
	cout << best << '\n';

	return 0;
}