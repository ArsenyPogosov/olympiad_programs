#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

long long solve1()
{
	vector<int> fenv(n);

	auto add = [&](int i)
	{
		while (i < n)
		{
			fenv[i] += 1;
			i = (i | (i + 1));
		}
	};

	auto sum = [&](int i)
	{
		int res = 0;
		while (i >= 0)
		{
			res += fenv[i];
			i = (i & (i + 1)) - 1;
		}
		return res;
	};

	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		res += i - sum(a[i]);
		add(a[i]);
	}
	return res;
}

int solve2()
{
	vector<int> A = a, b(n);
	for (int i = 0; i < n; ++i)
		b[a[i]] = i;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (b[i] == i) continue;
		++res;
		int p1 = i, p2 = b[i], v1 = A[i], v2 = i;
		swap(A[p1], A[p2]);
		swap(b[v1], b[v2]);
	}
	return res;
}

int solve3()
{
	vector<int> dp(n, 1e9);
	for (int i = 0; i < n; ++i)
		*upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
	int res; for (res = 0; res < n - 1 && dp[res + 1] < 1e9; ++res);
	return n - res - 1;
}

int solve4()
{
	vector<int> b(n);
	for (int i = 0; i < n; ++i)
		b[a[i]] = i;
	int res; for (res = n - 1; res > 0 && b[res] > b[res - 1]; --res);
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n);
	for (auto& i : a) cin >> i, --i;
	cout << solve1() << ' ' << solve2() << ' ' << solve3() << ' ' << solve4() << '\n';

	return 0;
}