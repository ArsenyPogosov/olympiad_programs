#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> a;

struct node
{
	long long sum;
	node *l, *r;
	node(long long x = 0) : sum(x), l(nullptr), r(nullptr) {}
};
typedef node* tree;

vector<tree> root;

void fix(tree v)
{
	if (!v || !v->l) return;
	v->sum = v->l->sum + v->r->sum;
}

tree build(long long l = 0, long long r = n)
{
	if (l + 1 == r)
	{
		return new node(a[l]);
	}
	tree res = new node;
	long long m = (l + r) / 2;
	res->l = build(l, m);
	res->r = build(m, r);
	fix(res);
	return res;
}

tree change(tree v, long long l, long long r, long long i, long long val)
{
	if (i < l || r <= i) return v;
	if (l + 1 == r) return new node(val);
	tree res = new node();
	long long m = (l + r) / 2;
	res->l = change(v->l, l, m, i, val);
	res->r = change(v->r, m, r, i, val);
	fix(res);
	return res;
}

void change(long long k, long long i, long long val)
{
	root[k] = change(root[k], 0, n, i, val);
}

long long query(tree v, long long l, long long r, long long L, long long R)
{
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return v->sum;
	long long m = (l + r) / 2;
	return query(v->l, l, m, L, R) + query(v->r, m, r, L, R);
}

long long sum(long long k, long long l, long long r)
{
	return query(root[k], 0, n, l, r + 1);
}

void copy(long long k)
{
	root.push_back(root[k]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long q; cin >> n >> q; a.resize(n); root.reserve(q);
	for (auto& i : a) cin >> i;
	root.push_back(build());
	while (q--)
	{
		long long reg; cin >> reg;
		if (reg == 1)
		{
			long long k, a, x; cin >> k >> a >> x;
			change(k - 1, a - 1, x);
		}
		if (reg == 2)
		{
			long long k, a, b; cin >> k >> a >> b;
			cout << sum(k - 1, a - 1, b - 1) << '\n';
		}
		if (reg == 3)
		{
			long long k; cin >> k;
			copy(k - 1);
		}
	}

	return 0;
}