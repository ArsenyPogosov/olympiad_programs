#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	if (n % 2 == 0)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 1; i <= n; ++i)
			cout << i * 2 - (i % 2) << ' ';
		for (int i = 1; i <= n; ++i)
			cout << i * 2 - ((i + 1) % 2) << ' ';
	}

	return 0;
}