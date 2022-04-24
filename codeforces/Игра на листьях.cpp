#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int count = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b;
			if (a == x || b == x) ++count;
		}
		if (count == 1 || n == 1)
			cout << "Ayush\n";
		else
		{
			if (n % 2 == 0)
				cout << "Ayush\n";
			else
				cout << "Ashish\n";

		}
	}

	return 0;
}