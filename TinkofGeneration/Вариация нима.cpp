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
		while (n--)
		{
			int h; cin >> h;
			if (h % 4 == 3)
				++h;
			else if (h % 4 == 0)
				--h;

			res ^= h;
		}
		cout << (res ? "FIRST" : "SECOND") << '\n';
	}

	return 0;
}