#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	if (s < n * 2)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n - 1; ++i)
		cout << 2 << ' ';
	cout << s - (n - 1) * 2 << "\n1\n";

	return 0;
}