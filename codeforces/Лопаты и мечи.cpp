#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		if (a < b) swap(a, b);
		int res = 0, d = a - b, t = min(b, d);
		res += t; a -= t * 2; b -= t;
		t = min(a / 3, b / 3);
		res += t * 2;
		a -= t * 3; b -= t * 3;
		while (a != 0 && b != 0)
		{
			if (a < b) swap(a, b);
			if (a == 1) break;
			res += 1;
			a -= 2;
			b -= 1;
		}
		cout << res << '\n';

	}

	return 0;
}