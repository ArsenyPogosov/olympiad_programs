#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int x, y, size;
	node *l, *r;
	node(int x = 0) : x(x), y(rand()), size(1), l(nullptr), r(nullptr) {};
};
typedef node* tree;

int size(tree v)
{
	if (!v) return 0;
	return v->size;
}

void fix(tree v)
{
	if (!v) return;
	v->size = size(v->l) + 1 + size(v->r);
}

pair<tree, tree> split(tree t, int k)
{
	if (!t) return { nullptr, nullptr };
	int ls = size(t->l);
	if (ls >= k)
	{
		auto res = split(t->l, k);
		t->l = res.second;
		fix(t);
		res.second = t;
		return res;
	}
	else
	{
		auto res = split(t->r, k - ls - 1);
		t->r = res.first;
		fix(t);
		res.first = t;
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

int del(tree &t, int i)
{
	auto t1t23 = split(t, i);
	auto t2t3 = split(t1t23.second, 1);
	int res = (t2t3.first ? t2t3.first->x : -1);
	t = merge(t1t23.first, t2t3.second);
	return res;
}

void push_back(tree& t, int val)
{
	t = merge(t, new node(val));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	tree t = nullptr;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		push_back(t, h);
	}
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		cout << del(t, h - 1) << ' ';
	}
	cout << '\n';

	return 0;
}