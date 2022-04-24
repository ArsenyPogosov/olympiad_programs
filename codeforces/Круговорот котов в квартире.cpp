#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k; --k;
		if (n % 2)
		{
			int x = (k / (n - 1)) % n, y = k % (n - 1);
			if (y < (n - 1) / 2)
				cout << (x + y) % n + 1 << '\n';
			else
				cout << (x + y + 1) % n + 1 << '\n';
		}
		else
		{
			cout << (k % n) + 1 << '\n';
		}
	}

	return 0;
}