#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> fenv;

void change(long long i, long long add)
{
	while (i < n)
	{
		fenv[i] += add;
		i |= (i + 1);
	}
}

void addlr(long long l, long long r, long long add)
{
	change(l, add);
	if (r + 1 < n) change(r + 1, -add);
}

long long get(long long i)
{
	long long res = 0;
	while (i >= 0)
	{
		res += fenv[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long q; cin >> n >> q;
	fenv.resize(n);
	for (int i = 0; i < n; ++i)
	{
		long long x; cin >> x;
		addlr(i, i, x);
	}
	while (q--)
	{
		long long reg; cin >> reg;
		if (reg == 1)
		{
			long long l, r, add; cin >> l >> r >> add;
			addlr(l - 1, r - 1, add);
		}
		if (reg == 2)
		{
			long long k; cin >> k;
			cout << get(k - 1) << '\n';
		}
	}

	return 0;
}