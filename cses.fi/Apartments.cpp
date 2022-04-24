#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (auto& i : a) cin >> i; sort(a.begin(), a.end());
	for (auto& i : b) cin >> i; sort(b.begin(), b.end());
	int count = 0, it = 0;
	for (auto& i : a)
	{
		while (it < m && b[it] + k < i) ++it;
		if (it >= m) break;
		if (abs(b[it] - i) <= k)
		{
			++it;
			++count;
		}
	}
	cout << count << '\n';

	return 0;
}