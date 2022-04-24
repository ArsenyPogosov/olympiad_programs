//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260618/problem/B
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
	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int l = 0, r = 100001;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		vector<int> b(n + 1);
		b[0] = min(a[0], m);
		b[1] = a[0] - b[0];
		bool flag = true;
		for (int i = 1; i < n; ++i)
		{
			int all = a[i], add;
			add = min(all, m - b[i - 1]);
			all -= add; b[i - 1] += add;
			add = min(all, m - b[i]);
			all -= add; b[i] += add;
			add = min(all, m - b[i + 1]);
			all -= add; b[i + 1] += add;
			if (all > 0)
			{
				flag = false;
				break;
			}
		}
		if (b[n] <= 0 && flag)
			r = m;
		else
			l = m;
	}
	cout << r;

	return 0;
}