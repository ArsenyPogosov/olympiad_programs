#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

const long long INF = 1000000000000000000;

long long UltPow(long long k, long long n)
{
	if (n == 0)
		return 1;
	long long res;
	if (n % 2 == 1)
	{
		res = UltPow(k, n - 1);
		if (res == INF)
			return INF;
		if (INF / res <= k)
			return INF;
		return res * k;
	}
	else
	{
		res = UltPow(k, n / 2);
		if (res == INF)
			return INF;
		if (INF / res <= res)
			return INF;
		return res * res;
	}
}

int main()
{
	long long k, n;
	cin >> k >> n;
	long long l{ 0 }, r{ 1000000000000000000 };
	while (l + 1 < r)
	{
		if (n <= UltPow(k + 1, (l + r) / 2))
			r = (l + r) / 2;
		else
			l = (l + r) / 2;
	}
	cout << r;

	return 0;
}