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
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		for (int i = 0; i < n; ++i)
			if (i % 2 == 0)
				cout << abs(a[i]) << ' ';
			else
				cout << -abs(a[i]) << ' ';
		cout << '\n';
	}

	return 0;
}