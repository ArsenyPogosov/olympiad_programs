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
	int ttt; cin >> ttt;
	for (int tt = 0; tt < ttt; ++tt)
	{
		int n, k1, k2; cin >> n >> k1 >> k2;
		int m = -1;
		for (int i = 0; i < k1; ++i)
		{
			int h; cin >> h;
			m = max(m, h);
		}
		bool flag = false;
		for (int i = 0; i < k2; ++i)
		{
			int h; cin >> h;
			if (h > m)
			{
				cout << "NO\n";
				flag = true;
				m = 1000000000;
			}
		}
		if (!flag)
		{
			cout << "YES\n";
		}
	}

	return 0;
}