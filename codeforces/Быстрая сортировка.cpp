#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for (auto& i : a) cin >> i;
	vector<pair<int, int>> result; result.reserve(15000);
	for (int i = 0; i < n; ++i)
	{
		int start;
		for (start = i; start < n; ++start) if (a[start] == i + 1) break;
		while (start > i)
		{
			int l = i + 1 - ((start - i) % 2), r = start;
			result.push_back({ l, r });
			start = (start - l - 1) / 2 + l;
			vector<int> help; help.reserve(r - l + 1);
			for (int j = l + 1; j <= r; j += 2)
				help.push_back(a[j]);
			for (int j = l; j <= r; j += 2)
				help.push_back(a[j]);
			for (int j = 0; j < r - l + 1; ++j)
				a[l + j] = help[j];
		}
	}
	cout << result.size() << '\n';
	for (auto& i : result)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';

	return 0;
}