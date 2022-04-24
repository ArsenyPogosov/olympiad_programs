#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;

	return GCD(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	int gcd;
	cin >> gcd;
	for (int i = 1; i < n; ++i)
	{
		int h;
		cin >> h;
		gcd = GCD(h, gcd);
	}
	int x;
	cin >> x;
	if (x % gcd == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}