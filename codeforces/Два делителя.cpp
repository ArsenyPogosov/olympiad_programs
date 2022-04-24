#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> resh(1e7 + 1);
	for (int i = 2; i < 1e7 + 1; ++i)
		if (resh[i] == 0)
		{
			resh[i] = i;
			if (i * 1ll * i <= 1e7)
				for (int j = i * i; j <= 1e7; j += i)
					resh[j] = i;
		}
	int n; cin >> n;
	string s2 = "";
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a;
		int p1 = 1, p2 = 1;
		while (a > 1)
		{
			int d = resh[a];
			p1 *= d;
			p2 = d;
			while (!(a % d))
				a /= d;
		}
		p1 /= p2;
		if (p1 >= 2 && p2 >= 2)
		{
			cout << p1 << ' ';
			s2 += to_string(p2) + ' ';
		}
		else
		{
			cout << -1 << ' ';
			s2 += "-1 ";
		}
	}
	cout << '\n' << s2 << '\n';

	return 0;
}