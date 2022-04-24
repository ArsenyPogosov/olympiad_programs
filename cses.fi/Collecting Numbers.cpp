#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	vector<int> a(n);

	for (int i = 0, h; i < n; ++i)
		cin >> h, a[h - 1] = i;

	int res = 1;
	for (int i = 1; i < n; ++i)
		res += (a[i] < a[i - 1]);

	cout << res << '\n';

	return 0;
}