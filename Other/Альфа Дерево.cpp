#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
int a, b, c, m;

int solve(int depth, int l, int mn, int mx)
{
	if (mn == mx) return mn;

	if (depth == n)
		return  max(mn, min(mx, int((n % 2 ? -1 : 1) * (a * int64_t(l) % m * l + int64_t(b) * l + c) % m)));

	int res = mn;
	res = -solve(depth + 1, l + (1 << (n - depth - 1)), -mx, -res);
	res = -solve(depth + 1, l, -mx, -res);

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> a >> b >> c >> m;
	cout << solve(0, 0, -m - 1, m + 1) << '\n';

	return 0;
}