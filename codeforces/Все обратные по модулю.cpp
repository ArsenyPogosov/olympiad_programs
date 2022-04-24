#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int p; cin >> p;
	vector<int> obr(p); obr[1] = 1;
	for (int i = 2; i < p; ++i)
	{
		obr[i] = p - (p / i) * 1ll * obr[p % i] % p;
	}
	for (int i = 1; i < p; i += 100)
		cout << accumulate(obr.begin() + i, obr.begin() + min(i + 100, p), 0ll) % p << '\n';

	return 0;
}