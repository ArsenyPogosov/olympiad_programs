#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t; cin >> t;
	while (t--)
	{
		long long x, y, a, b; cin >> x >> y >> a >> b;
		if (y < x) swap(x, y);
		if (2 * a <= b)
			cout << (x + y) * a << '\n';
		else
			cout << x * b + (y - x) * a << '\n';
	}

	return 0;
}