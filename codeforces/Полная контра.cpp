//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258319/attachments/download/6442/statements.pdf
//status: coding

#include <set>
#include <iostream>
#include <vector>
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
	vector<vector<char>> a(n, vector<char>(n));
	for (auto& i : a) for (auto& j : i) cin >> j;
	int s1, s2, s3, s4, s5;
	cin >> s1 >> s2 >> s3 >> s4 >> s5; --s1; --s2; --s3; --s4; --s5;
	vector<int> b(n);
	for (int i = 0; i < n; ++i)
	{
		if (a[s1][i] == '1') b[i] = 1;
		if (a[s2][i] == '1') b[i] = 1;
		if (a[s3][i] == '1') b[i] = 1;
		if (a[s4][i] == '1') b[i] = 1;
		if (a[s5][i] == '1') b[i] = 1;
		if (i == s1) b[i] = 1;
		if (i == s2) b[i] = 1;
		if (i == s3) b[i] = 1;
		if (i == s4) b[i] = 1;
		if (i == s5) b[i] = 1;
	}
	set<int> dt;
	bool c1, c2, c3, c4, c5;
	c1 = c2 = c3 = c4 = c5 = false;
	for (int i = 0; i < n; ++i)
		if (b[i] == 0)
		{
			if (!c1 && a[i][s1] == '1') { dt.insert(i); c1 = true; }
			if (!c2 && a[i][s2] == '1') { dt.insert(i); c2 = true; }
			if (!c3 && a[i][s3] == '1') { dt.insert(i); c3 = true; }
			if (!c4 && a[i][s4] == '1') { dt.insert(i); c4 = true; }
			if (!c5 && a[i][s5] == '1') { dt.insert(i); c5 = true; }
		}
	if (!(c1 && c2 && c3 && c4 && c5))
		cout << "NO";
	else
	{
		cout << "YES\n";
		for (int i = 0; dt.size() < 5; ++i)
			if (b[i] == 0)
				dt.insert(i);
		for (auto& i : dt)
			cout << i + 1 << ' ';
	}

	return 0;
}