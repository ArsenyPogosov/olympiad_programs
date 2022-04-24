#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long res = 0;
	vector<int> a(n);
	for (auto& i : a)
	{
		cin >> i;
		int h; cin >> h; res += h;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i)
		res -= 1ll * a[i] * (n - i);
	cout << res << '\n';

	return 0;
}