//source: 
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
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s; int n = s.size();
		int count1 = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '1') break;
			++count1;
		}
		for (int i = n-1; i >= 0; --i)
		{
			if (s[i] == '1') break;
			++count1;
		}
		int count2 = 0;
		for (auto& i : s) if (i == '1') ++count2;
		if (count2 == 0)
			cout << "0\n";
		else
			cout << n - count1 - count2 << '\n';
	}

	return 0;
}