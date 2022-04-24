#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		int ra = n, rb = m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				int h; cin >> h;
				if (h == 0) continue;
				if (a[i] == 0)
				{
					a[i] = 1; --ra;
				}
				if (b[j] == 0)
				{
					b[j] = 1; --rb;
				}
			}
		int res = min(ra, rb);
		if (res % 2 == 1)
			cout << "Ashish\n";
		else
			cout << "Vivek\n";
	}

	return 0;
}