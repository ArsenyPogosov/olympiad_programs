#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, p; cin >> n >> p;
	vector<int> obr(n + 1); obr[1] = 1;
	for (int i = 2; i <= n; ++i)
		obr[i] = p - p / i * 1ll * obr[p % i] % p;

	cout << accumulate(obr.begin(), obr.end(), 0ll) << '\n';

	return 0;
}