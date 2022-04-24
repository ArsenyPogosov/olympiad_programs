#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, k;
vector<int> a, ord;

vector<int> res;

int get(int mask, int l, int r)
{
	return ((mask >> l) & ((1 << (r - l + 1)) - 1));
}

void solve(int l, int r, int p)
{
	if (p < 0)
	{
		for (int i = l; i <= r; ++i)
			res.push_back(ord[i]);

		return;
	}

	if (get(k, p, p) == 0)
	{
		int i = l;
		while (i <= r && get(a[ord[i]], p, p) == 0)
			++i;
		if (l <= i - 1)
			solve(l, i - 1, p - 1);
		if (i <= r)
			solve(i, r, p - 1);

		return;
	}

	vector<pair<int, int>> targ{ {0, get(k, 0, p)} };
	for (int j = p; j >= 0; --j)
	{
		int curr = get(k, j, p);
		if (curr % 2 == 0)
			targ.emplace_back(j, curr + 1);
	}

	for (auto& h : targ)
	{
		int j = h.first, val = h.second;
		unordered_map<int, int> f;
		for (int i = l; i <= r; ++i)
		{
			int curr = get(a[ord[i]], j, p);
			if (f.find(val ^ curr) != f.end())
			{
				res.push_back(f[val ^ curr]);
				res.push_back(ord[i]);
				return;
			}
			f[curr] = ord[i];
		}
	}

	res.push_back(ord[l]);
}

int main()
{
	cin >> n >> k;

	a.resize(n);
	for (auto& i : a) cin >> i;

	ord.resize(n); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j]; });

	solve(0, n - 1, 29);
	if (res.size() > 1)
	{
		cout << res.size() << '\n';
		for (auto& i : res)
			cout << i + 1 << ' ';
		cout << '\n';
	}
	else
	{
		cout << "-1\n";
	}


	return 0;
}