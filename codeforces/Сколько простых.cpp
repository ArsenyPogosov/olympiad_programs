#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<char> prime(n + 1, true); prime[0] = false;
	for (long long i = 2; i <= n; ++i)
		for (long long j = (n * n + i - 1) / i; j * i <= n * n + n; ++j)
			prime[j * i - n * n] = false;

	cout << accumulate(prime.begin(), prime.end(), 0) << '\n';

	return 0;
}