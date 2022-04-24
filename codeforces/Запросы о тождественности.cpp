//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258319/problem/A
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
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == i + 1) ++count;
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (a[x - 1] == x) --count;
		if (a[y - 1] == y) --count;
		swap(a[x - 1], a[y - 1]);
		if (a[x - 1] == x) ++count;
		if (a[y - 1] == y) ++count;
		cout << (count == n ? "YES\n" : "NO\n");
	}

	return 0;
}