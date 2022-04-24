#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) cin >> i;

	vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) {
		return a[x] < a[y];
	});

	int bres = 0, ires = -1, tek = 0, was = -k - 1;
	for (int i = 0; i < n; ++i)
	{
		if (was + k < a[ord[i]])
		{
			if (bres < tek)
			{
				bres = tek;
				ires = i - tek;
			}
			tek = 0;
		}
		++tek;
		was = a[ord[i]];
	}
	if (bres < tek)
	{
		bres = tek;
		ires = n - tek;
	}

	cout << bres << '\n';
	for (int i = 0; i < bres; ++i)
		cout << ord[i + ires] + 1 << ' ';
	cout << '\n';

	return 0;
}