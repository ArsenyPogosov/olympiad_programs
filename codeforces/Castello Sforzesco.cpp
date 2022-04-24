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
	int n; string s; cin >> n;
	for (int i = 0; i < n; ++i) { int h; cin >> h; s += '0' + h; }
	while (true)
	{
		string ns; int it = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (ns.size() == 0)
				ns += s[i];
			else
			{
				if (ns[ns.size() - 1] == s[i])
					ns += s[i];
				else
					ns.erase(--ns.end());
			}
		}
		if (s == ns) break;
		s = ns;
	}
	cout << (s.size() >= 1 ? "NO" : "YES");

	return 0;
}