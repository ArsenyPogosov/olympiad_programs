#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int n;
vector<vector<vector<int>>> fenv;

int f(int x)
{
	return x&(x + 1);
}

void add(int x, int y, int z, int d)
{
	for (int i = x; i < n; i = i | (i + 1))
		for (int j = y; j < n; j = j | (j + 1))
			for (int k = z; k < n; k = k | (k + 1))
				fenv[i][j][k] += d;
}

int sum(int x, int y, int z)
{
	int res = 0;
	for (int i = x; i >= 0; i = f(i) - 1)
		for (int j = y; j >= 0; j = f(j) - 1)
			for (int k = z; k >= 0; k = f(k) - 1)
				res += fenv[i][j][k];
	return res;
}

int sum(int x1, int y1, int z1, int x2, int y2, int z2)
{
	return sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) - sum(x2, y2, z1 - 1) + sum(x1 - 1, y1 - 1, z2) + sum(x2, y1 - 1, z1 - 1) + sum(x1 - 1, y2, z1 - 1) - sum(x1 - 1, y1 - 1, z1 - 1);
}

int main()
{
	cin >> n;
	fenv.resize(n, vector<vector<int>>(n, vector<int>(n)));
	while (true)
	{
		int m;
		cin >> m;
		if (m == 1)
		{
			int x, y, z, d;
			cin >> x >> y >> z >> d;
			add(x, y, z, d);
		}
		if (m == 2)
		{
			int x1, y1, z1, x2, y2, z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			cout << sum(x1, y1, z1, x2, y2, z2) << '\n';
		}
		if (m == 3)
			break;
	}
	return 0;
}