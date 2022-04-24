#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x; cin >> x;
	int count = 0;
	while (x)
	{
		count += x % 2;
		x /= 2;
	}
	cout << count << '\n';

	return 0;
}