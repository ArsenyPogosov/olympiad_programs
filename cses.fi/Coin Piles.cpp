#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		cout << ((!((a + b) % 3) && b <= a * 2) ? "YES" : "NO") << '\n';
	}

	return 0;
}