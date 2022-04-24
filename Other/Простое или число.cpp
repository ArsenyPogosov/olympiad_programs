#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n; cin >> n;
	if (n == 1)
	{
		cout << "No\n";
		return 0;
	}
	int count = 0, f = n % 2;
	while(n > 0)
	{
		count += n % 2;
		n /= 2;
	}
	if (count <= 1)
		cout << "Yes\n";
	if (count == 2 && f == 1)
		cout << "Yes\n";
	if (count == 2 && f == 0)
		cout << "No\n";
	if (count > 2)
		cout << "No\n";

	return 0;
}