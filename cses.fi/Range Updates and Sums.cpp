#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> a;

struct node
{
	long long sum, add, change;
	bool tochange;

	node(long long x = 0) : sum(x), add(0), change(0), tochange(false) {};
};

vector<node> tree;

node merge(node a, node b)
{
	return node(a.sum + b.sum);
}

void fix(long long v)
{
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void add(long long v, long long l, long long r, long long tadd)
{
	tree[v].sum += tadd * (r - l);
	tree[v].add += tadd;
}

void change(long long v, long long l, long long r, long long val)
{
	tree[v].sum = val * (r - l);
	tree[v].add = 0;
	tree[v].change = val;
	tree[v].tochange = true;
}

void push(long long v, long long l, long long r)
{
	long long m = (l + r) / 2;
	if (tree[v].tochange)
	{
		change(v * 2 + 1, l, m, tree[v].change);
		change(v * 2 + 2, m, r, tree[v].change);
		tree[v].tochange = false;
	}
	if (tree[v].add)
	{
		add(v * 2 + 1, l, m, tree[v].add);
		add(v * 2 + 2, m, r, tree[v].add);
		tree[v].add = 0;
	}
}

void build(long long v = 0, long long l = 0, long long r = n)
{
	if (l + 1 == r)
	{
		tree[v] = node(a[l]);
		return;
	}
	long long m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

void add(long long v, long long l, long long r, long long L, long long R, long long tadd)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		add(v, l, r, tadd);
		return;
	}
	long long m = (l + r) / 2;
	push(v, l, r);
	add(v * 2 + 1, l, m, L, R, tadd);
	add(v * 2 + 2, m, r, L, R, tadd);
	fix(v);
}

void add(long long l, long long r, long long tadd)
{
	add(0, 0, n, l, r + 1, tadd);
}

void change(long long v, long long l, long long r, long long L, long long R, long long val)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		change(v, l, r, val);
		return;
	}
	long long m = (l + r) / 2;
	push(v, l, r);
	change(v * 2 + 1, l, m, L, R, val);
	change(v * 2 + 2, m, r, L, R, val);
	fix(v);
}

void change(long long l, long long r, long long val)
{
	change(0, 0, n, l, r + 1, val);
}

node query(long long v, long long l, long long r, long long L, long long R)
{
	if (r <= L || R <= l) return node();
	if (L <= l && r <= R)
	{
		return tree[v];
	}
	long long m = (l + r) / 2;
	push(v, l, r);
	return merge(query(v * 2 + 1, l, m, L, R), query(v * 2 + 2, m, r, L, R));
}

long long sum(long long l, long long r)
{
	return query(0, 0, n, l, r + 1).sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long q; cin >> n >> q; a.resize(n); tree.resize(n * 4);
	for (auto& i : a) cin >> i;
	build();
	while (q--)
	{
		long long reg, l, r; cin >> reg >> l >> r; --l; --r;
		if (reg == 1)
		{
			long long x; cin >> x;
			add(l, r, x);
		}
		if (reg == 2)
		{
			long long x; cin >> x;
			change(l, r, x);
		}
		if (reg == 3)
		{
			cout << sum(l, r) << '\n';
		}
	}

	return 0;
}