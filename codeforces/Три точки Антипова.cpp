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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int count = 0;
	for (auto& i : a)
	{
		if (i >= 2200)
			++count;
		else
			count = 0;
		if (count >= 3)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}