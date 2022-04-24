#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());
	int count = 1;
	for (int i = 1; i < n; ++i) count += a[i] != a[i - 1];
	cout << count << '\n';

	return 0;
}