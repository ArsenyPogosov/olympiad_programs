#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a, b;

struct Node
{
	long long sum = 0, addval = 0;
	int toadd = 0;

	Node(long long sum = 0, long long addval = 0, int toadd = 0) : sum(sum), addval(addval), toadd(toadd) {}
};

Node merge(const Node& l, const Node& r)
{
	return Node(l.sum + r.sum, l.addval + r.addval, 0);
}

void add(Node& v, int k)
{
	v.sum += v.addval * k;
	v.toadd += k;
}

vector<Node> tree;

void fix(int v)
{
	tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void push(int v)
{
	if (!tree[v].toadd) return;

	add(tree[v * 2 + 1], tree[v].toadd);
	add(tree[v * 2 + 2], tree[v].toadd);
	tree[v].toadd = 0;
}

void build(int v, int l, int r)
{
	if (l + 1 == r)
	{
		tree[v] = Node(a[l], b[l]);
		return;
	}

	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	fix(v);
}

Node get(int v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return Node();
	if (L <= l && r <= R) return tree[v];

	push(v);
	int m = (l + r) / 2;
	return merge(get(v * 2 + 1, l, m, L, R), get(v * 2 + 2, m, r, L, R));
}

void add(int v, int l, int r, int L, int R, int k)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		add(tree[v], k);
		return;
	}

	push(v);
	int m = (l + r) / 2;
	add(v * 2 + 1, l, m, L, R, k);
	add(v * 2 + 2, m, r, L, R, k);
	fix(v);
}

void build()
{
	tree.resize(n * 4);
	build(0, 0, n);
}

long long sum(int l, int r)
{
	return get(0, 0, n, l, r + 1).sum;
}

void add(int l, int r, int k)
{
	add(0, 0, n, l, r + 1, k);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	a.resize(n);
	for (auto& i : a) cin >> i;
	b.resize(n);
	for (auto& i : b) cin >> i;

	build();

	int m; cin >> m;
	while (m--)
	{
		char h; int l, r; cin >> h >> l >> r;
		if (h == '?')
		{
			cout << sum(l, r) << '\n';
		}
		if (h == '+')
		{
			add(l, r, 1);
		}
	}

	return 0;
}