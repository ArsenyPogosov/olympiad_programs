#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long inf = 1e18;

long long N;

struct func
{
	long long k, b;
	func(long long k = 0, long long b = inf) : k(k), b(b) {}

	long long operator()(long long x)
	{
		return k * x + b;
	}
};

vector<func> tree;

void add(long long v, long long l, long long r, func f)
{
	if (f(l) >= tree[v](l) && f(r) >= tree[v](r)) return;
	if (f(l) <= tree[v](l) && f(r) <= tree[v](r))
	{
		tree[v] = f;
		return;
	}

	long long m = (l + r) / 2;
	add(v * 2 + 1, l, m, f);
	add(v * 2 + 2, m, r, f);
}

void add(func f)
{
	add(0, 0, N, f);
}

long long get(long long v, long long l, long long r, long long x)
{
	long long res = tree[v](x), m = (l + r) / 2;
	if (l + 1 < m && l <= x && x < m) res = min(res, get(v * 2 + 1, l, m, x));
	if (l + 1 < m && m <= x && x < r) res = min(res, get(v * 2 + 2, m, r, x));

	return res;
}

long long get(long long x)
{
	return get(0, 0, N, x);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, x; cin >> n >> x;

	N = 1e6 + 1;
	tree.resize(N * 4);

	vector<long long> s(n), f(n);
	for (auto& i : s) cin >> i;
	for (auto& i : f) cin >> i;

	for (long long i = n - 1; i >= 0; --i)
		add(func(s[i], (i < n - 1 ? get(f[i]) : 0 )));

	cout << get(x) << '\n';

	return 0;
}