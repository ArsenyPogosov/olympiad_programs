#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long res = (long long)(n + 1) * n / 2;
	for (int i = 0; i < n - 1; ++i)
	{
		int h; cin >> h;
		res -= h;
	}
	cout << res;

	return 0;
}