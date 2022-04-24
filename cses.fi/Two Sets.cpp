#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	if (n % 4 == 0)
	{
		cout << "YES\n";
		cout << n / 2 << '\n';
		for (int i = 1; i <= n / 4; ++i) cout << i << ' ';
		for (int i = n / 4 * 3 + 1; i <= n; ++i) cout << i << ' ';
		cout << '\n' << n / 2 << '\n';
		for (int i = n / 4 + 1; i <= n / 4 * 3; ++i) cout << i << ' ';
		cout << '\n';
		return 0;
	}
	if (n % 4 == 3)
	{
		cout << "YES\n";
		cout << n / 2 + 1 << '\n' << "1 2 ";
		int k = (n - 3) / 4;
		for (int i = 4; i < 4 + k; ++i) cout << i << ' ';
		for (int i = 4 + k * 3; i <= n; ++i) cout << i << ' ';
		cout << '\n' << n / 2 << '\n' << "3 ";
		for (int i = 4 + k; i < 4 + k * 3; ++i) cout << i << ' ';
		cout << '\n';
		return 0;
	}
	cout << "NO\n";

	return 0;
}