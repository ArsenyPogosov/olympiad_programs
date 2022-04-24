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
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			int h; cin >> h;
			res ^= h;
		}
		cout << (res ? "first" : "second") << '\n';
	}

	return 0;
}