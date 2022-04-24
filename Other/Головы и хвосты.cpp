#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long x, y, a, b, n; cin >> x >> y >> a >> b >> n;

	long long res = 0;
	if (x > n && a >= n)
	{
		cout << -1 << '\n';
		return 0;
	}

	while (x > n)
		x -= n - a, ++res;

	if (x == n)
		x = 0, ++res;

	if (x == 0)
	{
		cout << res - 1 << '\n';
		return 0;
	}

	if (n - x <= y)
	{
		cout << res + 1 - 1 << '\n';
		return 0;
	}

	long long t = res;
	if (n - x <= t)
	{
		cout << res + 1 - 1 << '\n';
		return 0;
	}

	x += t;
	y -= (1 - b) * t;

	if (n - x <= y)
	{
		cout << res + 1 - 1 << '\n';
		return 0;
	}

	if (y < n || b <= n)
	{
		cout << -1 << '\n';
		return 0;
	}

	while (n - x > y)
		y -= n - b, ++res;

	cout << res + 1 - 1 << '\n';

	return 0;
}