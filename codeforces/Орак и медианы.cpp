#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		bool havek = false;
		for (auto&i: a)
			if (i == k)
			{
				havek = true; 
				break;
			}
		if (!havek)
		{
			cout << "no\n";
			continue;
		}
		if (n == 1)
		{
			cout << "yes\n";
			continue;
		}
		bool res = false;
		int prev = -100;
		for (int i = 0; i < n; ++i)
			if (a[i] >= k)
			{
				if (i - prev <= 2)
				{
					res = true;
					break;
				}
				prev = i;
			}
		cout << (res ? "yes" : "no") << '\n';
	}

	return 0;
}