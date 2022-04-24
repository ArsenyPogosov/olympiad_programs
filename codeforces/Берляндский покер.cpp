#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m, k; cin >> n >> m >> k;
		int have = min(m, n / k), other = (m - have + k - 2) / (k - 1);
		cout << have - other << '\n';
	}

	return 0;
}