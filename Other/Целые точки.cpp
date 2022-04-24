
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> res{ 1, 5, 25, 65, 325, 1105, 5525, 27625, 32045, 160225, 801125, 1185665, 5928325, 29641625, 48612265 };

	int n; cin >> n;
	cout << *--upper_bound(res.begin(), res.end(), n) << '\n';

	return 0;
}