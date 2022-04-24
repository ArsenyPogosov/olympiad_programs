#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 998244353;

int n;
vector<int> a, iprev, d, dps;

int sum(int l, int r)
{
	return ((dps[r] - (l > 0 ? dps[l - 1] : 0)) % p + p) % p;
}

struct node
{
	int covcount, res;
	node() : covcount(0), res(0) {};
};

vector<node> tree;

void fix(int v)
{
	if (tree[v].covcount) return;
	tree[v].res = (tree[v * 2 + 1].res + tree[v * 2 + 2].res) % p;
}

void del(int v, int l, int r)
{
	--tree[v].covcount;
	if (!tree[v].covcount)
	{
		if (l < r)
			fix(v);
		else
			tree[v].res = 0;
	}
}

void add(int v, int l, int r)
{
	if (!tree[v].covcount) tree[v].res = sum(l, r);
	++tree[v].covcount;
}

void del(int v, int l, int r, int L, int R)
{
	if (r < L || R < l) return;
	if (L <= l && r <= R)
	{
		del(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	del(v * 2 + 1, l, m, L, R);
	del(v * 2 + 2, m + 1, r, L, R);
	fix(v);
}

void add(int v, int l, int r, int L, int R)
{
	if (r < L || R < l) return;
	if (L <= l && r <= R)
	{
		add(v, l, r);
		return;
	}
	int m = (l + r) / 2;
	add(v * 2 + 1, l, m, L, R);
	add(v * 2 + 2, m + 1, r, L, R);
	fix(v);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; 
	a.resize(n); iprev.resize(n); d.resize(n + 1); dps.resize(n + 1); tree.resize(n * 4);
	for (auto& i : a) { cin >> i; --i; }
	vector<int> last(n, -1);
	for (int i = 0; i < n; ++i)
	{
		iprev[i] = last[a[i]];
		last[a[i]] = i;
	}
	d[0] = dps[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		if (iprev[i] != -1)
			del(0, 0, n - 1, iprev[iprev[i]] + 1, iprev[i]);
		add(0, 0, n - 1, iprev[i] + 1, i);
		d[i + 1] = tree[0].res;
		dps[i + 1] = (d[i + 1] + dps[i]) % p;
	}
	cout << d[n] << '\n';

	return 0;
}