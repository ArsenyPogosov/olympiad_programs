#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int s = 0;
		for (int i = 0, h; i < n; ++i) cin >> h, s += h;

		if (s < n)
			cout << 1 << '\n';
		else
			cout << s - n << '\n';
	}

	return 0;
}