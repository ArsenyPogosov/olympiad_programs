#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int x, y, len;
	node *l, *r;

	node (int x = 0): x(x), y(rand() * RAND_MAX + rand()), len(1), l(nullptr), r(nullptr) {}
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

void split(treap t, int x, treap& t1, treap& t2)
{
	if (!t)
	{
		t1 = t2 = nullptr;
		return;
	}

	if (t->x >= x)
	{
		split(t->l, x, t1, t->l);
		fix(t);
		t2 = t;
		return;
	}
	else
	{
		split(t->r, x, t->r, t2);
		fix(t);
		t1 = t;
		return;
	}
}

void add(treap& t, int x)
{
	treap t1, t2;
	split(t, x, t1, t2);
	t = merge(merge(t1, new node(x)), t2);
}

int cnt(treap& t, int x)
{
	treap t1, t2;
	split(t, x, t1, t2);
	int res = len(t1);
	t = merge(t1, t2);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b) {
		return pair<int, int>{ x[a], -y[a] } < pair<int, int>{x[b], -y[b]};
	});

	vector<int> a(n), b(n);

	treap t = nullptr;
	for (int i = n - 1; i >= 0; --i)
	{
		a[ord[i]] = cnt(t, y[ord[i]] + 1);
		add(t, y[ord[i]]);
	}

	t = nullptr;
	for (int i = 0; i < n; ++i)
	{
		b[ord[i]] = i - cnt(t, y[ord[i]]);
		add(t, y[ord[i]]);
	}

	for (auto& i : a)
		cout << i << ' ';
	cout << '\n';
	for (auto& i : b)
		cout << i << ' ';
	cout << '\n';

	return 0;
}