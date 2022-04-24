#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	if (n == 2 || n == 3)
	{
		cout << "NO SOLUTION\n";
		return 0;
	}
	for (int i = 2; i <= n; i += 2) cout << i << ' ';
	for (int i = 1; i <= n; i += 2) cout << i << ' ';
	cout << '\n';

	return 0;
}