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
		sort(a.begin(), a.end());
		int count = 1, tekcount = 0;
		for (int i = 0; i < n; ++i)
		{
			++tekcount;
			if (count + tekcount - 1 >= a[i])
			{
				count += tekcount;
				tekcount = 0;
			}
		}
		cout << count << '\n';
	}

	return 0;
}