#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long A, B, C, D; cin >> A >> B >> C >> D;
	long long res = 0;
	for (int a = A; a <= B; ++a)
	{
		long long l = max(B, C - a + 1), r = min(C, D - a + 1);
		if (l <= r)
		{
			long long x = a + l - 1 - C + 1, y = a + r - 1 - C + 1;
			res += (x + y) * (y - x + 1) / 2;
		}
		if (D - a + 2 <= C)
		{
			l = max(B, D - a + 2);
			res += (C - l + 1) * (D - C + 1);
		}
	}
	cout << res << '\n';

	return 0;
}