#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int cnt1(int x)
{
	int count = 0;
	while (x)
	{
		count += x % 2;
		x /= 2;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(m + 1);
	for (auto& i : a) cin >> i;
	int count = -1;
	for (auto& i : a) count += (cnt1(i ^ a[m]) <= k);
	cout << count << '\n';

	return 0;
}