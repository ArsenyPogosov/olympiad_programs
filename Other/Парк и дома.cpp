#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;

	cout << "4\n";
	cout << "0 0\n";
	cout << "0 1\n";
	cout << "1 1\n";
	cout << "1 0\n";

	vector<int> x{-1, -1, -1,  0, 0,  1, 1, 1};
	vector<int> y{-1,  0,  1, -1, 1, -1, 0, 1};

	for (int i = 0; i < n; ++i)
		cout << x[i] << ' ' << y[i] << '\n';

	return 0;
}