#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, b, n; cin >> a >> b >> n;
		int k = 0;
		while (max(a, b) <= n)
		{
			++k;
			if (a > b) swap(a, b);
			a = a + b;
		}
		cout << k << '\n';
	}
	return 0;
}