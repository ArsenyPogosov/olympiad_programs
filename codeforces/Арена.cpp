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
		int targ = *min_element(a.begin(), a.end()), res = n;
		for (auto& i : a)
			if (i == targ)
				--res;

		cout << res << '\n';
	}

	return 0;
}