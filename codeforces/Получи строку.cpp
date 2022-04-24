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
		int n, m;
		string s, t; cin >> s >> t;
		n = s.size(); m = t.size();
		vector<vector<int>> h(n + 1, vector<int>('z' - 'a' + 1, -1));
		for (int i = n - 1; i >= 0; --i)
		{
			h[i] = h[i + 1];
			h[i][s[i] - 'a'] = i;
		}
		int count = 1, tek = 0;
		for (int i = 0; i < m; ++i)
		{
			if (h[tek][t[i] - 'a'] == -1) { ++count; tek = 0; }
			tek = h[tek][t[i] - 'a'] + 1;
			if (tek == 0)
			{
				count = -1;
				break;
			}
		}
		cout << count << '\n';
	}

	return 0;
}