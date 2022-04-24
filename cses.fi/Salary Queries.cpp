#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int x, count, size, y;
	node *l, *r;
	node(int x = 0) : x(x), count(1), size(1), y(rand()), l(nullptr), r(nullptr) {};
};
typedef node* tree;

int size(tree t)
{
	if (!t) return 0;
	return t->size;
}

void fix(tree t)
{
	if (!t) return;
	t->size = size(t->l) + t->count + size(t->r);
}

pair<tree, tree> split(tree t, int val)
{
	if (!t) return { nullptr, nullptr };

	if (t->x <= val)
	{
		auto res = split(t->r, val);
		t->r = res.first;
		fix(t);
		res.first = t;
		return res;
	}
	else
	{
		auto res = split(t->l, val);
		t->l = res.second;
		fix(t);
		res.second = t;
		return res;
	}
}

tree merge(tree a, tree b)
{
	if (!a) return b;
	if (!b) return a;

	if (a->y < b->y)
	{
		a->r = merge(a->r, b);
		fix(a);
		return a;
	}
	else
	{
		b->l = merge(a, b->l);
		fix(b);
		return b;
	}
}

void del(tree& t, int val)
{
	auto t1t23 = split(t, val - 1);
	auto t2t3 = split(t1t23.second, val);
	if (t2t3.first)
	{
		if (!--t2t3.first->count)
			t2t3.first = nullptr;
	}
	fix(t2t3.first);
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
}

void add(tree &t, int val)
{
	auto t1t23 = split(t, val - 1);
	auto t2t3 = split(t1t23.second, val);
	if (t2t3.first)
		++t2t3.first->count;
	else
		t2t3.first = new node(val);
	fix(t2t3.first);
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
}

int countlr(tree &t, int l, int r)
{
	auto t1t23 = split(t, l - 1);
	auto t2t3 = split(t1t23.second, r);
	int res = size(t2t3.first);
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
	return res;
}

int n;
vector<int> a;
tree t = nullptr;

void change(int i, int val)
{
	del(t, a[i]);
	a[i] = val;
	add(t, a[i]);
}

int query(int l, int r)
{
	return countlr(t, l, r);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin >> n >> m; a.resize(n);
	for (auto& i : a) cin >> i;
	for (auto& i : a) add(t, i);
	while (m--)
	{
		char reg; cin >> reg;
		if (reg == '!')
		{
			int k, x; cin >> k >> x;
			change(k - 1, x);
		}
		if (reg == '?')
		{
			int a, b; cin >> a >> b;
			cout << query(a, b) << '\n';
		}
	}
	cout << '\n';

	return 0;
}