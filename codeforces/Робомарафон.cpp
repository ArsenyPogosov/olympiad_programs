#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, p;
vector<int> a;

struct node
{
	int x, y, count, size;
	node* l, * r;
	node() : x(0), count(0), size(0), y(rand()), l(nullptr), r(nullptr) {};
	node(int x) : x(x), count(1), size(1), y(rand()), l(nullptr), r(nullptr) {};
};
typedef node* tree;

int len(tree t)
{
	if (!t) return 0;
	return t->size;
}

void fix(tree t)
{
	if (!t) return;
	t->size = len(t->l) + t->count + len(t->r);
}

tree merge(tree l, tree r)
{
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y)
	{
		l->r = merge(l->r, r);
		fix(l);
		return l;
	}
	else
	{
		r->l = merge(l, r->l);
		fix(r);
		return r;
	}
}

pair<tree, tree> split(tree t, int targ)
{
	if (!t) return { nullptr, nullptr };
	if (t->x <= targ)
	{
		auto res = split(t->r, targ);
		t->r = res.first;
		fix(t);
		res.first = t;
		return res;
	}
	if (t->x > targ)
	{
		auto res = split(t->l, targ);
		t->l = res.second;
		fix(t);
		res.second = t;
		return res;
	}
}

void add(tree& t, int x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	if (!t2t3.first)
		t2t3.first = new node(x);
	else
	{
		++t2t3.first->count;
		++t2t3.first->size;
	}
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
}

void del(tree& t, int x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	if (t2t3.first)
	{
		--t2t3.first->count;
		--t2t3.first->size;
		if (!t2t3.first->size) t2t3.first = nullptr;
	}
	t1t23.second = merge(t2t3.first, t2t3.second);
	t = merge(t1t23.first, t1t23.second);
}

int Small(tree& t, int x)
{
	auto t1t2 = split(t, x - 1);
	int res = len(t1t2.first);
	t = merge(t1t2.first, t1t2.second);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> p;
	a.resize(n);
	for (auto& i : a) cin >> i;
	if (p == 1 && n <= 0)
	{
		for (int i = 0; i < n; ++i)
		{
			int count = 0;
			for (int j = 0; j < n; ++j)
				if (a[j] + abs(j - i) < a[i])
					++count;
			cout << count + 1 << '\n';
		}
		return 0;
	}
	if (p == 1 && n > 0)
	{
		tree l = nullptr, r = nullptr;
		for (int i = 0; i < n; ++i)
			add(r, a[i] + i);
		for (int i = 0; i < n; ++i)
		{
			del(r, a[i] + i);
			if (i - 1 >= 0)
				add(l, a[i - 1] + n - i);
			int count = 0;
			count += Small(l, a[i] + (n - i - 1));
			count += Small(r, a[i] + i);
			cout << count + 1 << '\n';
		}
		return 0;
	}
	if (p == 2)
	{
		for (int i = 0; i < n; ++i)
		{
			int best = -1;
			for (auto& dist : {i, n - i - 1})
			{
				int count = 0;
				for (int j = 0; j < n; ++j)
				{
					int start = n;
					if (abs(j - i) >= dist)
						start = 0;
					else
					{
						if (i - dist >= 0)
							start = min(start, abs(j - (i - dist)));
						if (i + dist < n)
							start = min(start, abs(j - (i + dist)));
					}
					if (a[j] + start < a[i] + dist)
						++count;
				}
				best = max(best, count + 1);
			}
			cout << best << '\n';
		}
		return 0;
	}

	return 0;
}