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
		vector<int> e(n);
		for (auto& i : e) cin >> i;
		sort(e.begin(), e.end());
		long long sum = 0, count = 0;
		for (auto& i : e)
		{
			++sum;
			if (sum >= i)
			{
				++count; sum -= i;
			}

		}
		cout << count << '\n';
	}

	return 0;
}