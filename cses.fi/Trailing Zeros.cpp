#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n; int res = 0;
	while (n)
	{
		res += n / 5; n /= 5;
	}
	cout << res << '\n';

	return 0;
}