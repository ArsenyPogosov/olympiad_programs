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
	string s;
	cin >> s;
	bool del = false;
	for (int i = 0; i < s.size(); ++i)
	{
		if (del)
			cout << s[i];
		else
		{
			if (i == s.size() - 1) break;
			if (s[i] < s[i + 1])
				del = true;
			else
				cout << s[i];
		}
	}

	return 0;
}