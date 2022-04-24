#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

long long ppow(int a, int k)
{
	if (k == 0) return 1;
	if (k % 2 == 0)
	{
		long long res = ppow(a, k / 2);
		return res * res % p;
	}
	return ppow(a, k - 1) * a % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, k; cin >> a >> k;
		cout << ppow(a, k) << '\n';
	}

	return 0;
}