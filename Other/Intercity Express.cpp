#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node
{
	int mn;
	Node *left, *right;

	Node(int mn = 0) : mn(mn), left(nullptr), right(nullptr) {}
};
typedef Node* tree;

int mn(tree t)
{
	return (t ? t->mn : 0);
}

tree left(tree t)
{
	return (t ? t->left : nullptr);
}

tree right(tree t)
{
	return (t ? t->right : nullptr);
}

tree merge(tree left, tree right)
{
	tree res = new Node(min(mn(left), mn(right)));
	res->left = left; res->right = right;

	return res;
}

tree change(tree t, int l, int r, int i, int v)
{
	if (i + 1 <= l || r <= i) return t;
	if (i <= l && r <= i + 1)
		return new Node(v);

	int m = (l + r) / 2;
	return merge(change(left(t), l, m, i, v), change(right(t), m, r, i, v));
}

int first(tree t, int l, int r, int v)
{
	if (mn(t) > v) return -1;
	if (l + 1 == r) return l;

	int m = (l + r) / 2;
	int resl = first(left(t), l, m, v);
	if (resl != -1) return resl;
	return first(right(t), m, r, v);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, s, m; cin >> N >> s >> m;

	vector<vector<int>> data(m, vector<int>(3));
	vector<pair<int, int*>> tosort;
	vector<int> rvals(1);
	for (auto& i : data)
	{
		cin >> i[0] >> i[1] >> i[2]; --i[0];
		tosort.emplace_back(i[1], &i[1]);
		tosort.emplace_back(i[2], &i[2]);
	}
	sort(tosort.begin(), tosort.end());
	for (auto& i : tosort)
	{
		if (rvals.empty() || rvals.back() != i.first)
			rvals.push_back(i.first);

		*i.second = rvals.size() - 1;
	}
	if (rvals.back() != N)
		rvals.push_back(N);
	int n = rvals.size();

	vector<vector<pair<int, int>>> close(n);
	for (auto&i: data)
	{
		close[i[1]].emplace_back(i[2], i[0]);
	}

	vector<tree> trees(n, nullptr);
	for (int i = 1; i < n; ++i)
	{
		trees[i] = trees[i - 1];
		for (auto& j : close[i - 1])
			trees[i] = change(trees[i], 0, s, j.second, j.first);
	}

	int q; cin >> q;
	int p = 0;
	while (q--)
	{
		int l, r; cin >> l >> r; l += p; r += p;
		l = upper_bound(rvals.begin(), rvals.end(), l) - rvals.begin() - 1;
		r = lower_bound(rvals.begin(), rvals.end(), r) - rvals.begin();
		cout << (p = first(trees[r], 0, s, l) + 1) << '\n';
	}

	return 0;
}