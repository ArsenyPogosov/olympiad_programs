#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int res = 0, a = -1, b = -1;
	while (n--)
	{
		int h; cin >> h;
		if (a != h)
		{
			a = h;
			++res;
			continue;
		}
		if (b != h)
		{
			b = h;
			++res;
			continue;
		}
	}

	cout << res << '\n';

	return 0;
}