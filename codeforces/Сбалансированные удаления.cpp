//source: https://codeforces.com/contest/1237/problem/C1
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> points(n, vector<int>(4));
	for (int i = 0; i < n; ++i)
	{
		points[i][0] = i + 1;
		cin >> points[i][1] >> points[i][2] >> points[i][3];
	}
	sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
		if (a[1] < b[1])
			return true;
		return false;
		});
	int i = 0;
	while(i < n)
	{
		int xi = i + 2;
		while (xi < n && points[xi][1] == points[i + 1][1]) ++xi;
		if (xi >= n) --xi;
		if (points[xi][1] != points[i + 1][1]) --xi;
		sort(points.begin() + i, points.begin() + xi + 1, [](vector<int>& a, vector<int>& b) {
			if (a[2] < b[2])
				return true;
			return false;
			});
		int j = i;
		while(j < xi)
		{
			int yj = j + 2;
			while (yj <= xi && points[yj][2] == points[j + 1][2]) ++yj;
			if (yj > xi) --yj;
			if (points[yj][2] != points[j + 1][2]) --yj;
			sort(points.begin() + j, points.begin() + yj + 1, [](vector<int>& a, vector<int>& b) {
				if (a[3] < b[3])
					return true;
				return false;
				});
			int k = j;
			for (; k <= yj; k += 2)
				cout << points[k][0] << ' ' << points[k + 1][0] << '\n';
			j = k;
		}
		i = j;
	}

	return 0;
}