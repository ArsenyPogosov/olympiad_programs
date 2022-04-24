#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

long long k;
vector<long long> a, blockSum;

void Change(long long x, long long d)
{
	d -= a[x];
	a[x] += d;
	blockSum[x / k] += d;
}

long long Sum(long long l, long long r)
{
	long long res = 0;
	while (l % k != 0)
	{
		if (l > r)
			return res;
		res += a[l++];
	}
	while (r % k != k - 1)
	{
		if (r < l)
			return res;
		res += a[r--];
	}
	for (long long i = l / k; i < (r + 1) / k; ++i)
		res += blockSum[i];

	return res;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	k = max((long long)sqrt(n), 1ll);
	a.resize(n);
	blockSum.resize(n / k + 1);
	for (long long i = 0; i < m; ++i)
	{
		char h;
		long long x, y;
		cin >> h >> x >> y;
		if (h == 'A')
			Change(x - 1, y);
		if (h == 'Q')
			cout << Sum(x - 1, y - 1) << '\n';
	}

	return 0;
}