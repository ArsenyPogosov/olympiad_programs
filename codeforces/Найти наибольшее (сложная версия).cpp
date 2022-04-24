#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int ask(int l, int r)
{
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	int res; cin >> res;
	return  res - 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int s = ask(0, n - 1);
	int l, r;
	if (s > 0 && ask(0, s) == s)
	{
		l = 0; r = s;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (ask(m, s) == s)
				l = m;
			else
				r = m;
		}

		cout << "! " << l + 1 << endl;
	}
	else
	{
		l = s; r = n - 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (ask(s, m) == s)
				r = m;
			else
				l = m;
		}

		cout << "! " << r + 1 << endl;
	}


	return 0;
}