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
	int n; cin >> n;
	int m = n + 8;
	bool flag = false;
	for (int i = 2; i * i <= m; ++i)
		if (m % i == 0)
		{
			flag = true;
			break;
		}
	if (flag)
	{
		cout << m << ' ' << 8;
	}
	else
	{
		cout << n + 9 << ' ' << 9;
	}

	return 0;
}