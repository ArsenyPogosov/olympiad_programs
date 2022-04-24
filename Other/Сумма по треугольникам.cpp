#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
//#pragma comment(linker, "/STACK:40000000")
using namespace std;

const int s = 1664525, t = 1013904223, p2 = 1e7;
const long long p1 = 1ll << 32;
long long x;

int Gen()
{
	int xx = x % p2; x = (s * x + t) % p1;
	return xx;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double t = clock();

	int n; 
	n = 3000; x = 228;
	//cin >> n >> x;
	//int mass[3000][3000];
	vector<vector<int>> mass(3000, vector<int>(3000));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			mass[i][j] = (i != j ? Gen() : 0);

	long long res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
				res += (min({ mass[i][j], mass[j][k], mass[k][i] }) +
					min({ mass[j][i], mass[i][k], mass[k][j] }));

	cout << res * 3 << '\n';

	cout << (clock() - t) / CLOCKS_PER_SEC << '\n';

	return 0;
}