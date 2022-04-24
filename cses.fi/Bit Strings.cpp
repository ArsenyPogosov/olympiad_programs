#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

long long Pow(long long a, long long b)
{
	if (b == 0) return 1;
	long long res = Pow(a, b / 2);
	return (res * res * (b % 2 ? a : 1)) % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cout << Pow(2, n) << '\n';

	return 0;
}