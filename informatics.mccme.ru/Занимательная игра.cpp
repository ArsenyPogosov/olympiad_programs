#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto&i : a)
		cin >> i;
	sort(a.begin(), a.end());
	int ans = n, r = 0;
	for (int l = 0; l < n; ++l)
	{
		while ((r < n)&&(a[r] <= a[l] + n - 1)) ++r;
		ans = min(ans, n - (r - l));
	}
	cout << ans;

	return 0;
}