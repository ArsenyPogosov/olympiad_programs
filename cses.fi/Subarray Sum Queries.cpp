#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	long long lsum, maxsum, rsum, allsum;
	node(long long x = 0)
	{
		lsum = maxsum = rsum = max(x, 0ll); allsum = x;
	}
};

node merge(node l, node r)
{
	node res;
	res.allsum = l.allsum + r.allsum;
	res.maxsum = max({ l.maxsum, r.maxsum, l.rsum + r.lsum });
	res.lsum = max(l.lsum, l.allsum + r.lsum);
	res.rsum = max(r.rsum, l.rsum + r.allsum);
	return res;
}

long long n;
vector<long long> a;
vector<node> tree;

void fix(long long v)
{
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
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

node query(long long v, long long l, long long r, long long L, long long R)
{
	if (r <= l || r <= L) return node();
	if (L <= l && r <= R) return tree[v];

	long long m = (l + r) / 2;
	return merge(query(v * 2 + 1, l, m, L, R), query(v * 2 + 2, m, r, L, R));
}

long long query(long long l, long long r)
{
	return query(0, 0, n, l, r).maxsum;
}

void change(long long v, long long l, long long r, long long i, long long nval)
{
	if (i < l || r <= i) return;
	if (l + 1 == r)
	{
		tree[v] = node(nval);
		return;
	}

	long long m = (l + r) / 2;
	change(v * 2 + 1, l, m, i, nval);
	change(v * 2 + 2, m, r, i, nval);
	fix(v);
}

void change(long long i, long long nval)
{
	change(0, 0, n, i, nval);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long q; cin >> n >> q; a.resize(n); tree.resize(n * 4);
	for (auto& i : a) cin >> i;
	build();

	while (q--)
	{
		long long a, b; cin >> a >> b;
		change(a - 1, b);
		cout << query(0, n) << '\n';
	}

	return 0;
}