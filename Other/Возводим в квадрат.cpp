#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	string h = "023456789";
	if (n <= 9)
		cout << n;
	else
		cout << h[(n - 1) % 9];
	cout << '\n';

	return 0;
}