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

	long long sum = 0;
	for (int i = 0; i < n && a[i] <= sum + 1; sum += a[i], ++i);
	cout << sum + 1 << '\n';

	return 0;
}