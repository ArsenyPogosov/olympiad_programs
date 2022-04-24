//source: https://codeforces.com/contest/1266/problem/0
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
	for (int kk = 0; kk < n; ++kk)
	{
		string s, s2; cin >> s;
		bool flag = false;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '0' && !flag)
				flag = true;
			else
				s2 += s[i];
		if (!flag)
		{
			cout << "cyan\n";
			continue;
		}
		flag = false;
		for (auto& i : s2)
			if ((i - '0') % 2 == 0)
				flag = true;
		if (!flag)
		{
			cout << "cyan\n";
			continue;
		}
		int count = 0;
		for (auto& i : s2)
			count += i - '0';
		if (count % 3 != 0)
		{
			cout << "cyan\n";
		}
		else
		{
			cout << "red\n";
		}
	}

	return 0;
}