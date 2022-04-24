//source: https://codeforces.com/gym/102330/problem/F
//status: solved

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

vector<int> a, b, c;
int n, s;

int ang(int i, int n)
{
	if (n <= c[i])
		return a[i];
	return b[i];
}

int main()
{
	cin >> n >> s;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i] >> c[i];

	vector<int> shaf(n);
	for (int i = 0; i < n; ++i) shaf[i] = i;
	int l = 0, r = n + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		sort(shaf.begin(), shaf.end(), [&](int a, int b) {
			if (ang(a, m) < ang(b, m))
				return true;
			return false;
			});
		int sum = 0;
		for (int i = 0; i < m; ++i)
		{
			sum += ang(shaf[i], m);
			if (sum > s)
				break;
		}
		if (sum <= s)
			l = m;
		else
			r = m;
	}
	cout << l;

	return 0;
}