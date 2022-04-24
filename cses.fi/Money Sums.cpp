#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> can(1000 * n + 1); can[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		for (int j = n * 1000; j >= x; --j)
			can[j] |= can[j - x];
	}
	cout << accumulate(can.begin() + 1, can.end(), 0) << '\n';
	for (int i = 1; i <= n * 1000; ++i)
		if (can[i])
			cout << i << ' ';
	cout << '\n';

	return 0;
}