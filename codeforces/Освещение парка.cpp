#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		cout << (n * m + 1) / 2 << '\n';
	}

	return 0;
}