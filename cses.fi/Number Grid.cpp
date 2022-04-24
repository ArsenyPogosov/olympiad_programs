#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int res(int n, int x, int y)
{
	if (n == 1) return 0;

	bool add = false;
	if (x >= n / 2)
	{
		add = !add;
		x -= n / 2;
	}
	if (y >= n / 2)
	{
		add = !add;
		y -= n / 2;
	}
	return res(n / 2, x, y) + add * n / 2;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y; cin >> x >> y;
	cout << res(1 << 30, x - 1, y - 1) << '\n';

	return 0;
}