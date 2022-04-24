#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto&i : a)
		cin >> i;
	sort(a.begin(), a.end());
	vector<int> L(n), R(n);
	L[0] = 0;
	int target = 0;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] - a[target] <= L[target] + 1)
		{
			L[i] = L[target] + 1;
		}
		else
		{
			if (i - target == 1)
			{
				L[i] = a[i] - a[target];
				target = i;
			}
			else
			{
				--i;
				target = i;
			}
		}
	}
	R[n - 1] = 0;
	target = n - 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (a[target] - a[i] <= R[target] + 1)
		{
			R[i] = R[target] + 1;
		}
		else
		{
			if (target - i == 1)
			{
				R[i] = a[target] - a[i];
				target = i;
			}
			else
			{
				++i;
				target = i;
			}
		}
	}
	double ans = 2000000000;
	L[0] = R[n - 1] = -1;
	for (int i = 0; i < n; ++i)
	{
		int l = i, r = n - 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if ((a[m] - a[i]) / 2.0 > R[m] + 1.0)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		ans = min(ans, max(L[i] + 1.0, max((a[l] - a[i]) / 2.0, R[l] + 1.0)));
		ans = min(ans, max(L[i] + 1.0, max((a[r] - a[i]) / 2.0, R[r] + 1.0)));
	}
	int ans1 = int(ans * 10);
	cout << ans1 / 10 << '.' << ans1 % 10;

	return 0;
}