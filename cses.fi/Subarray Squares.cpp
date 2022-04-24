#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long inf = 1e18;

int N;
vector<int> val;

struct func
{
	int k; long long b;
	func(int k = 0, long long b = inf): k(k), b(b) {}

	long long operator()(int x)
	{
		return k * 1ll * x + b;
	}
};

vector<func> tree;

void add(int v, int l, int r, func f)
{
	if (f(val[l]) >= tree[v](val[l]) && f(val[r - 1]) >= tree[v](val[r - 1])) return;
	if (f(val[l]) <= tree[v](val[l]) && f(val[r - 1]) <= tree[v](val[r - 1]))
	{
		tree[v] = f;
		return;
	}

	int m = (l + r) / 2;
	add(v * 2 + 1, l, m, f);
	add(v * 2 + 2, m, r, f);
}

void add(func f)
{
	add(0, 0, N, f);
}

long long get(int v, int l, int r, int x)
{
	long long res = tree[v](val[x]), m = (l + r) / 2;
	if (l + 1 < r && l <= x && x < m) res = min(res, get(v * 2 + 1, l, m, x));
	if (l + 1 < r && m <= x && x < r) res = min(res, get(v * 2 + 2, m, r, x));

	return res;
}

long long get(int x)
{
	return get(0, 0, N, x);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	val.resize(n + 1);
	for (int i = 1, h; i <= n; ++i) cin >> h, val[i] = val[i - 1] + h;

	N = n + 1;
	vector<long long> res(n + 2, inf); res[n + 1] = 0;
	for (int t = 0; t < k; ++t)
	{
		tree.assign(N * 4, func());
		vector<long long> tek(n + 2, inf); tek[n + 1] = 0;

		for (int i = n; i >= 1; --i)
		{
			add(func(-2 * val[i], val[i] * 1ll * val[i] + res[i + 1]));
			if (n - i < t)
				tek[i] = res[i];
			else
				tek[i] = get(i - 1) + val[i - 1] * 1ll * val[i - 1];
		}

		res = tek;
	}

	cout << res[1] << '\n';

	return 0;
}