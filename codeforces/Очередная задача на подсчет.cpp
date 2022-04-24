#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long a, b, q; cin >> a >> b >> q;
		vector<int> s(a * b); s[0] = 0;
		for (int i = 1; i < a * b; ++i)
		{
			s[i] = s[i - 1];
			if (((i % a) % b) != ((i % b) % a))
				++s[i];
		}
		for (int i = 0; i < q; ++i)
		{
			long long l, r; cin >> l >> r;
			long long L = ((l + a * b - 1) / (a * b)) * a * b, R = (r / (a * b)) * (a * b);
			long long res = 0;
			if (R >= L)
			{
				if ((l % (a * b)) - 1 >= 0)
				{
					res = s[a * b - 1];
					res -= s[(l % (a * b)) - 1];
				}
				res += s[r % (a * b)];
				res += ((R - L) / (a * b))*s[a * b - 1];
			}
			else
			{
				l %= (a * b); r %= (a * b);
				res += s[r];
				if (l - 1 >= 0)
					res -= s[l - 1];
			}
			cout << res << ' ';
		}
		cout << '\n';
	}

	return 0;
}