#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n;
vector<long long> fenv;

void add(long long i)
{
	while (i < n)
	{
		fenv[i] += 1;
		i = (i | (i + 1));
	}
}

long long sum(long long i)
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
	cin >> n;
	vector<long long> x(n);
	vector<pair<long long, long long>> ord(n);
	for (long long i = 0; i < n; ++i)
	{
		long long h; cin >> h;
		ord[i] = { h, i };
	}
	sort(ord.begin(), ord.end());
	for (long long i = 0; i < n; ++i)
		x[ord[i].second] = i;
	fenv.assign(n, 0);
	long long res = 0;
	for (long long i = 0; i < n; ++i)
	{
		long long left = i - sum(x[i]);
		res += min(left, (n - x[i] - 1) - left);
		add(x[i]);
	}
	cout << res << '\n';

	return 0;
}