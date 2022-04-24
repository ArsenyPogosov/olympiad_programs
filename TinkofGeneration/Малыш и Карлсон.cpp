#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int f(int a)
{
	for (; a & 1; a >>= 1);
	return a >> 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b, c; cin >> a >> b >> c;

	int fa = f(a), fb = f(b), fc = f(c);
	int res = fa ^ fb ^ fc;
	if (!res)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";

	if ((fa ^ res) < fa)
	{
		int targ = fa ^ res, na = targ << 1;
		while ((na << 1) + 1 < a) na = (na << 1) + 1;

		cout << na << ' ' << b << ' ' << c << '\n';
		return 0;
	}
	if ((fb ^ res) < fb)
	{
		int targ = fb ^ res, nb = targ << 1;
		while ((nb << 1) + 1 < b) nb = (nb << 1) + 1;

		cout << a << ' ' << nb << ' ' << c << '\n';
		return 0;
	}
	if ((fc ^ res) < fc)
	{
		int targ = fc ^ res, nc = targ << 1;
		while ((nc << 1) + 1 < c) nc = (nc << 1) + 1;

		cout << a << ' ' << b << ' ' << nc << '\n';
		return 0;
	}

	return 0;
}