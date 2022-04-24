#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n), res(n * 2 + 5);
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		a[h - 1] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		b[h - 1] = i;
	}
	for (int i = 0; i < n; ++i)
		++res[(a[i] - b[i] + n * 2) % n];
	cout << *max_element(res.begin(), res.end()) << '\n';

	return 0;
}