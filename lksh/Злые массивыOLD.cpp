#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 998244353;

int n;
vector<int> a, iprev, d;

struct node
{
	vector<int> psum, count;
	int add, toadd;
	node() : add(0), toadd(0) {};
};

vector<node> tree;

void fix(int v)
{
	int l = 0, r = 0, x = tree[v * 2 + 1].count.size(), y = tree[v * 2 + 2].count.size();
	tree[v].add = 0;
	while (l < x && r < y)
	{
		if (tree[v * 2 + 1].count[l] + tree[v * 2 + 1].add > tree[v * 2 + 2].count[r] + tree[v * 2 + 2].add)
		{
			tree[v].count[l + r] = tree[v * 2 + 1].count[l] + tree[v * 2 + 1].add;
			++l;
		}
		else
		{
			tree[v].count[l + r] = tree[v * 2 + 2].count[r] + tree[v * 2 + 2].add;
			++r;
		}
		tree[v].psum[l + r - 1] = (l > 0 ? tree[v * 2 + 1].psum[l - 1] : 0);
		tree[v].psum[l + r - 1] = (tree[v].psum[l + r - 1] + (r > 0 ? tree[v * 2 + 2].psum[r - 1] : 0)) % p;
	}
	while (l < x)
	{
		tree[v].count[l + r] = tree[v * 2 + 1].count[l] + tree[v * 2 + 1].add;
		++l;
		tree[v].psum[l + r - 1] = (l > 0 ? tree[v * 2 + 1].psum[l - 1] : 0);
		tree[v].psum[l + r - 1] = (tree[v].psum[l + r - 1] + (r > 0 ? tree[v * 2 + 2].psum[r - 1] : 0)) % p;
	}
	while (r < y)
	{
		tree[v].count[l + r] = tree[v * 2 + 2].count[r] + tree[v * 2 + 2].add;
		++r;
		tree[v].psum[l + r - 1] = (l > 0 ? tree[v * 2 + 1].psum[l - 1] : 0);
		tree[v].psum[l + r - 1] = (tree[v].psum[l + r - 1] + (r > 0 ? tree[v * 2 + 2].psum[r - 1] : 0)) % p;
	}
}

void add(int v, int toadd)
{
	tree[v].add += toadd;
	tree[v].toadd += toadd;
}

void insert(int v, int i)
{
	tree[v].count.push_back(0 - tree[v].add);
	int dd = (tree[v].psum.size() != 0 ? tree[v].psum[tree[v].psum.size() - 1] : 0);
	dd = (dd + (i > 0 ? d[i - 1] : 1)) % p;
	tree[v].psum.push_back(dd);
}

void push(int v)
{
	if (!tree[v].toadd) return;
	add(v * 2 + 1, tree[v].toadd);
	add(v * 2 + 2, tree[v].toadd);
	tree[v].toadd = 0;
}

void add(int v, int l, int r, int L, int R, int toadd)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		add(v, toadd);
		return;
	}

	int m = (l + r) / 2;
	push(v);
	add(v * 2 + 1, l, m, L, R, toadd);
	add(v * 2 + 2, m, r, L, R, toadd);
	fix(v);
}

void insert(int v, int l, int r, int i)
{
	insert(v, i);
	if (r - l == 1) return;

	int m = (l + r) / 2;
	push(v);
	if (i < m)
		insert(v * 2 + 1, l, m, i);
	else
		insert(v * 2 + 2, m, r, i);
	//fix(v);
}

int tekres()
{
	int it = upper_bound(tree[0].count.rbegin(), tree[0].count.rend(), -tree[0].add) - tree[0].count.rbegin();
	it = tree[0].count.size() - it - 1;
	if (it < 0) return 0;
	return tree[0].psum[it];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n); iprev.resize(n); d.resize(n); tree.resize(n * 4);
	for (auto& i : a) { cin >> i; --i; }
	vector<int> last(n, -1);
	for (int i = 0; i < n; ++i)
	{
		iprev[i] = last[a[i]];
		last[a[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (iprev[i] != -1) 
			add(0, 0, n, iprev[iprev[i]] + 1, iprev[i] + 1, -1);
		insert(0, 0, n, i);
		add(0, 0, n, iprev[i] + 1, i + 1, 1);
		d[i] = tekres();
	}
	cout << d[n - 1] << '\n';

	return 0;
}