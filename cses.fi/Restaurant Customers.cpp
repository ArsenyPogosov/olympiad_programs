#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> t(n * 2);
	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b;
		t[i * 2] = { a, 1 };
		t[i * 2 + 1] = { b, -1 };
	}
	sort(t.begin(), t.end());
	int count = 0, mx = 0;
	for (auto& i : t)
	{
		count += i.second;
		mx = max(mx, count);
	}
	cout << mx << '\n';

	return 0;
}