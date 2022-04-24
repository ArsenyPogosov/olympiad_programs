#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	char h;
	int y, size;
	node *l, *r;

	node(char h = 0) : h(h), y(rand()* RAND_MAX + rand()), size(1), l(nullptr), r(nullptr) {};
};
typedef node* treap;

int size(treap t)
{
	return (t ? t->size : 0);
}

void fix(treap t)
{
	if (!t) return;

	t->size = size(t->l) + 1 + size(t->r);
}

treap merge(treap t1, treap t2)
{
	if (!t1) return t2;
	if (!t2) return t1;

	if (t1->y < t2->y)
	{
		t1->r = merge(t1->r, t2);
		fix(t1);
		return t1;
	}
	else
	{
		t2->l = merge(t1, t2->l);
		fix(t2);
		return t2;
	}
}

void split(treap t, int k, treap& t1, treap& t2)
{
	if (!t) { t1 = t2 = nullptr; return; }

	if (size(t->l) >= k)
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

void add(treap& t, char h)
{
	t = merge(t, new node(h));
}

char get(treap& t, int i)
{
	treap t1, t2t3, t2, t3;
	split(t, i, t1, t2t3);
	split(t2t3, 1, t2, t3);
	char res = t2->h;
	t = merge(t1, merge(t2, t3));

	return res;
}

void move(treap& t, int a, int b)
{
	treap t1, t2t3, t2, t3;
	split(t, a, t1, t2t3);
	split(t2t3, b - a + 1, t2, t3);
	t = merge(t1, merge(t3, t2));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	treap t = nullptr;
	int n, m; cin >> n >> m;
	char h;
	for (int i = 0; i < n; ++i)
		cin >> h, add(t, h);

	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		move(t, a - 1, b - 1);
	}

	for (int i = 0; i < n; ++i)
		cout << get(t, i);
	cout << '\n';

	return 0;
}