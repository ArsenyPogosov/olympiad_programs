#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		long long n, m; cin >> n >> m;

		cout << (((n / 2) + m - 1) / m) << '\n';
	}

	return 0;
}