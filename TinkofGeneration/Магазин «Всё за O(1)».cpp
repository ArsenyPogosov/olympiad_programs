#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	node* l, * r;
	int x, y, sz;
	bool rev;

	node(int x = 0) : x(x), y(rand()* RAND_MAX + rand()), sz(1), rev(false), l(nullptr), r(nullptr) {}
};
typedef node* treap;

void rev(treap t)
{
	if (!t) return;
	t->rev ^= 1;
	swap(t->l, t->r);
}

void push(treap t)
{
	if (t && t->rev)
	{
		if (t->l) rev(t->l);
		if (t->r) rev(t->r);
		t->rev = false;
	}
}

int size(treap t)
{
	return (t ? t->sz : 0);
}

void fix(treap t)
{
	if (!t) return;
	t->sz = size(t->l) + 1 + size(t->r);
}

void split(treap t, int k, treap& t1, treap& t2)
{
	if (!t)
	{
		t1 = t2 = nullptr;
		return;
	}

	push(t);
	if (k <= size(t->l))
	{
		split(t->l, k, t1, t->l);
		fix(t);
		t2 = t;
	}
	else
	{
		split(t->r, k - size(t->l) - 1, t->r, t2);
		fix(t);
		t1 = t;
	}
}

treap merge(treap t1, treap t2)
{
	if (!t1) return t2;
	if (!t2) return t1;

	if (t1->y < t2->y)
	{
		push(t1);
		t1->r = merge(t1->r, t2);
		fix(t1);
		return t1;
	}
	else
	{
		push(t2);
		t2->l = merge(t1, t2->l);
		fix(t2);
		return t2;
	}
}

int front(treap& t)
{
	treap t1, t2; split(t, 1, t1, t2);
	int res = t1->x;
	t = merge(t1, t2);

	return res;
}

int back(treap& t)
{
	treap t1, t2; split(t, size(t) - 1, t1, t2);
	int res = t2->x;
	t = merge(t1, t2);

	return res;
}

void push_front(treap& t, int x)
{
	t = merge(new node(x), t);
}

void push_back(treap& t, int x)
{
	t = merge(t, new node(x));
}

void pop_front(treap& t)
{
	split(t, 1, *new treap(), t);
}

void pop_back(treap& t)
{
	split(t, size(t) - 1, t, *new treap());
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	treap a = nullptr, b = nullptr;

	int n; cin >> n;
	for (int i = 0, t = 0; i < n; ++i)
	{
		char h; cin >> h;
		if (h == 'a')
		{
			push_back(a, t++);
		}
		if (h == 'b')
		{
			push_back(b, t++);
		}
		if (h == 'A')
		{
			cout << (front(a) + 1) % 10;
			pop_front(a);
		}
		if (h == 'B')
		{
			cout << (front(b) + 1) % 10;
			pop_front(b);
		}
		if (h == '>')
		{
			rev(a);
			b = merge(b, a);
			a = nullptr;
		}
		if (h == ']')
		{
			rev(b);
			a = merge(a, b);
			b = nullptr;
		}
		if (h == '<')
		{
			int k = min(size(b), (size(b) + size(a) + 1) / 2);
			treap t1, t2; split(b, k, t1, t2);
			b = t1;
			rev(t2);
			a = merge(a, t2);
		}
		if (h == '[')
		{
			int k = min(size(a), (size(a) + size(b) + 1) / 2);
			treap t1, t2; split(a, k, t1, t2);
			a = t1;
			rev(t2);
			b = merge(b, t2);
		}
	}

	cout << '\n';

	return 0;
}