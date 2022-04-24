#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	vector<int> turn(n);
	for (int i = 0; i < n; ++i)
		turn[i] = i;
	sort(turn.begin(), turn.end(), [&](int a, int b) { return x[a] < x[b]; });
	vector<int> p(n, -1), l(n, -1), r(n, -1);
	int it = -1;
	for (auto& i : turn)
	{
		int bit = -1;
		while (it != -1 && y[it] > y[i])
		{
			bit = it;
			it = p[it];
		}
		if (it >= 0)
		{
			r[it] = i;
			p[i] = it;
		}
		if (bit >= 0)
		{
			p[bit] = i;
			l[i] = bit;
		}
		it = i;
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << p[i] + 1 << ' ' << l[i] + 1 << ' ' << r[i] + 1 << '\n';

	return 0;
}