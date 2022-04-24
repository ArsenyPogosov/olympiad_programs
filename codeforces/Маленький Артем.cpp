#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		cout << "W";
		for (int i = 1; i < b; ++i)
			cout << "B";
		cout << '\n';
		for (int i = 1; i < a; ++i)
		{
			for (int j = 0; j < b; ++j)
				cout << "B";
			cout << '\n';
		}
	}
	return 0;
}