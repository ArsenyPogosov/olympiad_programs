#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int l = -1, r = n;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;

		int a, b;
		cout << "? " << m + 1 << endl;
		cin >> a;
		if (m + 1 < n)
		{
			cout << "? " << m + 2 << endl;
			cin >> b;
		}
		else
			b = 1e9;

		if (a > b)
			l = m;
		else
			r = m;
	}

	cout << "! " << r + 1 << endl;

	return 0;
}