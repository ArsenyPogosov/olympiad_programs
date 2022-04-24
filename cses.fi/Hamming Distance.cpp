#include <bits/stdc++.h>
#include <bitset>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;

	vector<bitset<30>> num(n);
	for (auto& i : num)
		cin >> i;

	int res = k;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			res = min(res, int((num[i] ^ num[j]).count()));
	cout << res << '\n';

	return 0;
}