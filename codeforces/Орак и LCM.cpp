#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long GCD(long long a, long long b)
{
	return b ? GCD(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long res = 0, pgcd; cin >> pgcd;
	for (int i = 1; i < n; ++i)
	{
		long long a; cin >> a;
		res = GCD(a * pgcd / GCD(a, pgcd), res);
		pgcd = GCD(a, pgcd);
	}
	cout << res << '\n';

	return 0;
}