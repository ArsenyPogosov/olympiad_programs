#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, xr = 0; cin >> n;
		vector<int> a(n);
		for (auto& i : a) cin >> i, xr ^= i;
		if (xr == 0)
		{
			cout << "DRAW\n";
			continue;
		}
		int big, X = 0, Y = 0;
		for (big = (1 << 30); big >= 1; big >>= 1)
			if (xr & (big)) break;
		for (auto& i : a)
			if (i & big)
				++X;
		Y = n - X;
		if (((X / 2) % 2)&&!(Y % 2))
			cout << "LOSE\n";
		else
			cout << "WIN\n";
	}

	return 0;
}