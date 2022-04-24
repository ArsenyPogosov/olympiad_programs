#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> a;

struct node
{
	long long sum, start, d;
	node(long long x = 0) : sum(x), start(0), d(0) {};
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

void addseq(long long v, long long l, long long r, long long start, long long d)
{
	tree[v].sum += (r - l) * (start + start + (r - l - 1) * d) / 2;
	tree[v].start += start;
	tree[v].d += d;
}

void push(long long v, long long l, long long r)
{
	if (tree[v].start || tree[v].d)
	{
		long long m = (l + r) / 2;
		addseq(v * 2 + 1, l, m, tree[v].start, tree[v].d);
		addseq(v * 2 + 2, m, r, tree[v].start + (m - l) * tree[v].d, tree[v].d);
		tree[v].start = tree[v].d = 0;
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

void addseq(long long v, long long l, long long r, long long L, long long R, long long start, long long d)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		addseq(v, l, r, start + (l - L) * d, d);
		return;
	}
	long long m = (l + r) / 2;
	push(v, l, r);
	addseq(v * 2 + 1, l, m, L, R, start, d);
	addseq(v * 2 + 2, m, r, L, R, start, d);
	fix(v);
}

void addseq(long long l, long long r, long long start, long long d)
{
	addseq(0, 0, n, l, r + 1, start, d);
}

node query(long long v, long long l, long long r, long long L, long long R)
{
	if (r <= L || R <= l) return node(0);
	if (L <= l && r <= R)
	{
		return tree[v];
	}
	long long m = (l + r) / 2;
	push(v, l, r);
	return merge(query(v * 2 + 1, l, m, L, R),
		query(v * 2 + 2, m, r, L, R));
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
			addseq(l, r, 1, 1);
		}
		if (reg == 2)
		{
			cout << sum(l, r) << '\n';
		}
	}

	return 0;
}