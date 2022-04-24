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
		vector<int> count(n);
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			int a; cin >> a; a = ((a + i) % n + n) % n;
			if (count[a] == 1)
				flag = false;;
			count[a] = 1;
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}

	return 0;
}