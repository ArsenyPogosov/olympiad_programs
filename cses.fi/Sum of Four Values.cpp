#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, x; cin >> n >> x;
	vector<long long> a(n), ord(n);
	for (auto& i : a) cin >> i;
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](long long l, long long r) { return a[l] < a[r]; });
	for (long long i = 0; i < n - 3; ++i)
	{
		if (a[ord[i]] + a[ord[i + 1]] + a[ord[i + 2]] + a[ord[i + 3]] > x)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		for (long long j = i + 1; j < n - 2; ++j)
		{
			int r = n - 1;
			for (int l = j + 1; l < r; ++l)
			{
				while (l < r && a[ord[l]] + a[ord[r]] > x - a[ord[i]] - a[ord[j]]) --r;
				if (l < r && a[ord[l]] + a[ord[r]] == x - a[ord[i]] - a[ord[j]])
				{
					cout << ord[i] + 1 << ' ' << ord[j] + 1 << ' ' << ord[l] + 1 << ' ' << ord[r] + 1 << '\n';
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
