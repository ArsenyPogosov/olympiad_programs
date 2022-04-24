#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	long long max, add;
	node(long long max = 0): max(max), add(0) {}
};

node merge(node a, node b)
{
	return node(max(a.max, b.max));
}

long long n;
vector<long long> mass;
vector<node> tree;

void fix(long long v)
{
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void build(long long v = 0, long long l = 0, long long r = n)
{
	if (l + 1 == r)
	{
		tree[v] = node(mass[l]);
		return;
	}

	long long m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

void add(long long v, long long val)
{
	tree[v].max += val;
	tree[v].add += val;
}

void push(long long v)
{
	add(v * 2 + 1, tree[v].add);
	add(v * 2 + 2, tree[v].add);
	tree[v].add = 0;
}

void add(long long v, long long l, long long r, long long L, long long R, long long val)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		add(v, val);
		return;
	}

	push(v);
	long long m = (l + r) / 2;
	add(v * 2 + 1, l, m, L, R, val);
	add(v * 2 + 2, m, r, L, R, val);
	fix(v);
}

void add(long long l, long long r, long long val)
{
	add(0, 0, n, l, r + 1, val);
}

node get(long long v, long long l, long long r, long long L, long long R)
{
	if (r <= L || R <= l) return node(-1e18);
	if (L <= l && r <= R)
	{
		return tree[v];
	}

	push(v);
	long long m = (l + r) / 2;
	return merge(get(v * 2 + 1, l, m, L, R),
		get(v * 2 + 2, m, r, L, R));
}

long long get(long long l, long long r)
{
	return get(0, 0, n, l, r + 1).max;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long q; cin >> n >> q;
	vector<long long> x(n);
	mass.resize(n);
	for (long long i = 0; i < n; ++i)
	{
		cin >> x[i];
		mass[i] = x[i] + (i ? mass[i - 1] : 0);
	}

	tree.resize(n * 4 + 5);
	build();

	while (q--)
	{
		long long h, a, b; cin >> h >> a >> b;
		if (h == 1)
		{
			add(a - 1, n - 1, -x[a - 1] + b);
			x[a - 1] = b;
		}
		if (h == 2)
		{
			cout << max(0ll, get(a - 1, b - 1) - (a - 2 >= 0 ? get(a - 2, a - 2) : 0)) << '\n';
		}
	}

	return 0;
}