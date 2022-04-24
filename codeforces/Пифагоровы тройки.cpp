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
		cout << max(0, (int(sqrt(n * 2 - 1) - 3 + 1 + 1) / 2)) << '\n';
	}

	return 0;
}