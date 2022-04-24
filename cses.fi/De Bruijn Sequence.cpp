#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<char> used(1 << n);
	int tek = 0, count = 0;
	for (int i = 0; i < n; ++i) cout << '0';
	while (count < (1 << n) - 1)
	{
		used[tek] = true;
		tek = ((tek & (~(1 << (n - 1)))) << 1) + 1;
		if (!used[tek])
			cout << '1';
		else
			cout << '0', --tek;
		++count;
	}
	cout << '\n';

	return 0;
}