#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int m = 30;

struct node
{
	node* p[2];
	node() { p[0] = p[1] = nullptr; };
};

node* root = new node;

int bit(int x, int i)
{
	return (x & (1ll << i)) != 0;
}

void add(node* v, int x, int i = m - 1)
{
	if (i < 0) return;
	if (!v->p[bit(x, i)])
		v->p[bit(x, i)] = new node;
	add(v->p[bit(x, i)], x % (1ll << i), i - 1);
}

int res(node* v, int x, int i = m - 1)
{
	if (i < 0) return 0;
	if (v->p[1 - bit(x, i)])
		return (1ll << i) + res(v->p[1 - bit(x, i)], x % (1ll << i), i - 1);
	return res(v->p[bit(x, i)], x % (1ll << i), i - 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int h = 0;
	for (auto& i : a)
	{
		h ^= i;
		add(root, h);
	}
	int mx = 0;
	h = 0;
	for (auto& i : a)
	{
		mx = max(mx, res(root, h));
		h ^= i;
	}
	cout << mx << '\n';

	return 0;
}
