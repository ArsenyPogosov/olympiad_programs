#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> c;
vector<vector<int>> graph;

int t = 0;
vector<int> tin, tout, path;
void DFS(int v, int p = -1)
{
	path[t] = v;
	tin[v] = t++;
	for (auto& i : graph[v])
		if (i != p)
			DFS(i, v);
	tout[v] = t;
}

struct node
{
	int count;
	node *l, *r;
	node(int x = 0) : count(x), l(nullptr), r(nullptr) {};
};
typedef node* tree;

vector<tree> root;

tree build(int l = 0, int r = n)
{
	if (l + 1 == r)
		return new node;
	tree res = new node;
	int m = (l + r) / 2;
	res->l = build(l, m);
	res->r = build(m, r);
	return res;
}

tree change(tree v, int l, int r, int i, int val)
{
	if (i < l || r <= i) return v;
	if (l + 1 == r) return new node(val);
	tree res = new node;
	int m = (l + r) / 2;
	res->l = change(v->l, l, m, i, val);
	res->r = change(v->r, m, r, i, val);
	res->count = res->l->count + res->r->count;
	return res;
}

tree change(int k, int i, int val)
{
	return change(root[k], 0, n, i, val);
}

int query(tree v, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return v->count;
	int m = (l + r) / 2;
	return query(v->l, l, m, L, R) + query(v->r, m, r, L, R);
}

int res(int v)
{
	int l = tin[v], r = tout[v];
	return query(root[r], 0, n, l, r);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; c.resize(n); graph.resize(n);
	for (auto& i : c) cin >> i;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	tin.resize(n); tout.resize(n); path.resize(n);
	DFS(0);
	vector<int> prev(n, -1);
	map<int, int> last;
	for (int i = n - 1; i >= 0; --i)
	{
		auto it = last.find(c[path[i]]);
		if (it == last.end())
			last[c[path[i]]] = i;
		else
		{
			prev[it->second] = i;
			it->second = i;
		}
	}
	root.resize(n + 1); root[0] = build();
	for (int i = 0; i < n; ++i)
	{
		root[i + 1] = root[i];
		if (prev[i] != -1)
			root[i + 1] = change(i + 1, prev[i], 0);
		root[i + 1] = change(i + 1, i, 1);
	}
	for (int i = 0; i < n; ++i)
		cout << res(i) << ' ';
	cout << '\n';

	return 0;
}