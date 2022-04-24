#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	string a, b; cin >> a >> b; int n = a.size();
	string beg, end;
	int c1 = 0, c2 = 0;
	while (c1 < n && a[c1] == b[c1])
		++c1;
	beg = a.substr(0, c1);
	while (c2 < n - c1 && a[n - c2 - 1] == b[n - c2 - 1])
		++c2;
	end = a.substr(n - c2, c2);
	int spr = n - c1 - c2;
	if (spr == 0)
	{
		cout << a << "a\n";
		return 0;
	}
	if (a.substr(c1, spr - 1) == b.substr(c1 + 1, spr - 1))
	{
		cout << beg << b[c1] << a.substr(c1, n) << '\n';
		return 0;
	}
	if (b.substr(c1, spr - 1) == a.substr(c1 + 1, spr - 1))
	{
		cout << beg << a[c1] << b.substr(c1, n) << '\n';
		return 0;
	}
	{
		cout << "IMPOSSIBLE";
	}

	return 0;
}