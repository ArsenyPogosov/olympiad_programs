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
		int a, b;
		cin >> a;
		for (int i = 1; i < n - 1; ++i) cin >> b;
		cin >> b;
		cout << (a < b ? "YES" : "NO") << '\n';
	}

	return 0;
}