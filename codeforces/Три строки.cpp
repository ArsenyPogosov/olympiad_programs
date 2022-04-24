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
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		bool flag = false;
		for (int i = 0; i < n; ++i)
			if (a[i] != c[i] && b[i] != c[i])
			{
				cout << "NO\n";
				flag = true;
				break;
			}
		if (flag) continue;
		cout << "YES\n";
	}

	return 0;
}