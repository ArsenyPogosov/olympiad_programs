//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258319/attachments/download/6442/statements.pdf
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

bool onb(int n, int i)
{
	return ((n >> i) % 2 == 1);
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int del;
	for (int i = 28; i >= 0; --i)
	{
		del = -1;
		for (int j = 0; j < n; ++j)
			if (!onb(a[j], i))
			{
				if (del == -1)
					del = j;
				else
				{
					del = -1;
					break;
				}
			}
		if (del != -1) break;
	}
	int res = (1 << 29) - 1;
	for (int i = 0; i < n; ++i)
		if (i != del) res &= a[i];
	cout << res;

	return 0;
}