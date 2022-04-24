#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> a, rval;

void squeeze()
{
	vector<int> order(n); iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int x, int y) {return a[x] < a[y]; });
	int tval = -1e9 - 1; m = 0; rval.reserve(n);
	for (auto& i : order)
	{
		if (tval < a[i])
		{
			rval.push_back(a[i]);
			tval = a[i];
			++m;
		}
		a[i] = m - 1;
	}
	++m;
}

vector<int> fenv;

void change(int i, int add)
{
	while (i < n)
	{
		fenv[i] += add;
		i = i | (i + 1);
	}
}

int sum(int i)
{
	int res = 0;
	while (i >= 0)
	{
		res += fenv[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

int sum(int l, int r)
{
	return sum(r) - sum(l - 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; a.resize(n);
	for (auto& i : a) cin >> i;
	squeeze();
	vector<pair<int, int>> query(q);
	for (auto& i : query) cin >> i.first >> i.second, --i.first, --i.second;
	vector<int> order(q); iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int x, int y) {return query[x] < query[y]; });
	vector<int> ans(q);
	vector<int> next(n, -1), tek(m, -1);
	fenv.resize(n);
	for (int i = 0; i < n; ++i)
	{
		if (tek[a[i]] != -1)
			next[tek[a[i]]] = i;
		else
			change(i, 1);
		tek[a[i]] = i;
	}
	int tl = 0;
	for (auto& i : order)
	{
		for (; tl < query[i].first; ++tl)
		{
			change(tl, -1);
			if (next[tl] != -1)
				change(next[tl], 1);
		}
		ans[i] = sum(query[i].first, query[i].second);
	}
	for (auto& i : ans) cout << i << '\n';

	return 0;
}