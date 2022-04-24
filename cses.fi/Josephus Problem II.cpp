#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int x, y, len;
	node *l, *r;

	node(int x = 0) : x(x), y(rand()* RAND_MAX + rand()), len(1), l(nullptr), r(nullptr) {}
};
typedef node* treap;

int len(treap t)
{
	return (t ? t->len : 0);
}

void fix(treap t)
{
	if (!t) return;
	t->len = len(t->l) + 1 + len(t->r);
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

void split(treap t, int k, treap &t1, treap &t2)
{
	if (!t)
	{
		t1 = t2 = nullptr;
		return;
	}

	if (len(t->l) >= k)
	{
		split(t->l, k, t1, t->l);
		fix(t);
		t2 = t;
	}
	else
	{
		split(t->r, k - len(t->l) - 1, t->r, t2);
		fix(t);
		t1 = t;
	}
}

void push_back(treap &t, int x)
{
	t = merge(t, new node(x));
}

int erase(treap& t, int k)
{
	treap t1, t23, t2, t3;
	split(t, k, t1, t23);
	split(t23, 1, t2, t3);
	t = merge(t1, t3);

	return t2->x;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;;
	treap t = nullptr;
	for (int i = 0; i < n; ++i)
		push_back(t, i);

	int it = 0;
	while (len(t))
	{
		it += k;
		it %= len(t);

		cout << erase(t, it) + 1 << ' ';
	}
	cout << '\n';

	return 0;
}