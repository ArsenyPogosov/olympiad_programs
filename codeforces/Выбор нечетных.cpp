#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, x; cin >> n >> x;
		int l = 0, r = 0;
		for (int i = 0; i < n; ++i)
		{
			int h; cin >> h;
			if (h % 2 == 0)
				++l;
			else
				++r;
		}
		if (r >= 1 && ((x - 1) - min((x - 1) / 2, (r - 1) / 2) * 2 <= l))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}