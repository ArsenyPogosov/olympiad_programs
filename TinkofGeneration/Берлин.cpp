#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, q; cin >> n >> k >> q;
	vector<char> a(n);
	for (auto& i : a) cin >> i, i -= '0';

	while (q--)
	{
		int l, r; cin >> l >> r; --l; --r;

		int res = 0; char sum = 0;
		vector<int> b(n + k);
		for (int i = l; i <= r; ++i)
		{
			if (i + k - 1 > r && b[i] ^ a[i] ^ (i > l ? a[i - 1] : 0) > 0)
			{
				res = -1;
				break;
			}
			res += b[i + k] = b[i] ^ a[i] ^ (i > l ? a[i - 1] : 0);			
		}

		cout << res << '\n';
	}

	return 0;
}