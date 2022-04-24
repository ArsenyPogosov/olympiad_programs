#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

long long n;
vector<long long> a;

int main()
{
	cin >> n;
	a.resize(n * 2);
	long long preAns = 0;
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
		preAns += max(0ll, abs(i - n / 2) - a[i]);
		a[i] = max(a[i] - abs(i - n / 2), 0ll);
	}
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i + n];
		preAns += max(0ll, abs(i - n / 2) - a[i + n]);
		a[i + n] = max(a[i + n] - abs(i - n / 2), 0ll);
	}
	sort(a.begin(), a.end());
	
	long long laAns = 1000000000000000000;
	long long sumMinus = 0, sumPlus = 0;
	for (int i = 0; i < n * 2; ++i) sumPlus += a[i];
	for (int i = 0; i < n * 2; ++i)
	{
		sumMinus += a[i];
		sumPlus -= a[i];
		laAns = min(laAns, (i + 1) * a[i] - sumMinus - (n * 2 - i - 1) * a[i] + sumPlus);
	}
	cout << preAns + laAns;

	return 0;
}