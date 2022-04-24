#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long a, b, c, d; cin >> a >> b >> c >> d;
		cout << (c - a) * (d - b) + 1 << '\n';
	}

	return 0;
}