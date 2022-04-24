#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	for (int i = n - 1; i >= 0; --i)
		swap(a[(n - i - 1) / 2], a[n - i - 1]);
	for (auto& i : a)
		cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}