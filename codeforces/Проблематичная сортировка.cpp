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
		vector<int> a(n), b(n);
		for (auto& i : a) cin >> i;
		for (auto& i : b) cin >> i;
		vector<int> c(2);
		for (auto& i : b) ++c[i];
		if (c[0] > 0 && c[1] > 0)
		{
			cout << "Yes\n"; continue;
		}
		bool flag = false;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] > a[i + 1])
			{
				cout << "No\n"; flag = true; break;
			}
		if (flag) continue;
		cout << "Yes\n";
	}

	return 0;
}