#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> d(n + 1, 1e9); d[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int h = i;
		while (h > 0)
		{
			d[i] = min(d[i], d[i - h % 10] + 1);
			h /= 10;
		}
	}
	cout << d[n] << '\n';

	return 0;
}