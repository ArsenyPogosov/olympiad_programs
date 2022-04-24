#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, l; cin >> n >> l;
	int res[2]; res[0] = res[1] = 0;
	for (int i = 0; i < n; ++i)
	{
		int t, d; cin >> t >> d; --t;
		if (d == -1)
		{
			res[t] += 1;
		}
		else if (d <= l)
		{
			res[t] += 2;
		}
		else
		{
			res[t] += 3;
		}
	}

	cout << res[0] << ':' << res[1] << '\n';

	return 0;
}