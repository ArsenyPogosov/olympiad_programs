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
		set<int> el;
		for (int i = 0; i < n; ++i)
		{
			int h; cin >> h;
			el.insert(h);
		}
		if (el.size() > k)
		{
			cout << "-1\n";
			continue;
		}
		vector<int> E(el.size());
		int it = 0;
		for (auto& i : el) E[it++] = i;
		cout << n * k << '\n';
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < k; ++j)
				cout << E[j % E.size()] << ' ';
		cout << '\n';
	}

	return 0;
}