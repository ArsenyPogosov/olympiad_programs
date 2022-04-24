#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < (1 << n); ++i, cout << '\n')
		for (int j = n - 1; j >= 0; --j)
			cout << (((i >> j) & 1) ^ ((i >> (j + 1)) & 1));

	return 0;
}