#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n = 1e6 + 1;
	vector<long long> r1(n), r2(n);

	r1[1] = 1;
	r2[1] = 1;

	for (int i = 2; i < n; ++i)
	{
		r1[i] = (r1[i - 1] * 2 + r2[i - 1]) % p;
		r2[i] = (r1[i - 1] + r2[i - 1] * 4) % p;
	}

	int q; cin >> q;
	while (q--)
	{
		cin >> n;
		cout << (r1[n] + r2[n]) % p << '\n';
	}

	return 0;
}