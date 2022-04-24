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

int main()
{
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	c += (a + 1) / 2;
	d += a / 2;
	int f = 0;
	f += a % 2;
	f = (f + b) % 2;
	if (c > d) cout << "Nastya";
	if (c < d) cout << "Slava";
	if (c == d)
	{
		if (f == 0) cout << "Slava";
		if (f == 1) cout << "Nastya";
	}

	return 0;
}