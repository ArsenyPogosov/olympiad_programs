#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	long long sum, suml, sumr;
	node() { sum = -1e18; };
};

long long n;
vector<long long> a, ps;

long long sumlr(long long l, long long r)
{
	return ps[r] - (l > 0 ? ps[l - 1] : 0);
}

node merge(node a, long long la, long long ra, node b, long long lb, long long rb)
{
	if (a.sum == -1e18) return b;
	if (b.sum == -1e18) return a;
	node res = node();
	res.suml = max(a.suml, sumlr(la, ra) + max(0ll, b.suml));
	res.sumr = max(b.sumr, sumlr(lb, rb) + max(0ll, a.sumr));
	res.sum = max({ a.sum, b.sum, a.sumr + max(0ll, b.suml), b.suml + max(0ll, a.sumr) });
	return res;
}

vector<node> tree;

void build(long long v, long long l, long long r)
{
	if (l == r)
	{
		tree[v].suml = tree[v].sum = tree[v].sumr = a[l];
		return;
	}
	long long m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	tree[v] = merge(tree[v * 2 + 1], l, m, tree[v * 2 + 2], m + 1, r);
}

node summm(long long v, long long l, long long r, long long L, long long R)
{
	if (r < L || R < l) return node();
	if (L <= l && r <= R) return tree[v];
	long long m = (l + r) / 2;
	return merge(summm(v * 2 + 1, l, m, L, R), l, m, summm(v * 2 + 2, m + 1, r, L, R), m + 1, r);
}

long long res(long long l, long long r, long long mx)
{
	return summm(0, 0, n - 1, l, r).sum - mx;
}

long long ans;
vector<long long> otrl, otrr;

void add(long long i, long long mx)
{
	long long l = i, r = i;
	if (i > 0 && otrr[i - 1] != -1) l = otrr[i - 1];
	if (i < n - 1 && otrl[i + 1] != -1) r = otrl[i + 1];
	ans = max(ans, res(l, r, mx));
	otrl[l] = r;
	otrr[r] = l;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n); ps.resize(n);
	otrl.resize(n, -1); otrr.resize(n, -1);
	for (auto& i : a) cin >> i;
	partial_sum(a.begin(), a.end(), ps.begin());
	tree.resize(n * 4); build(0, 0, n - 1);
	vector<vector<long long>> pos(61);
	for (long long i = 0; i < n; ++i) pos[a[i] + 30].push_back(i);
	for (long long i = 0; i < 61; ++i)
	{
		for (auto& j : pos[i]) add(j, i - 30);
	}
	cout << ans << '\n';
		
	return 0;
}