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
	int a, b;
	cin >> a >> b;
	if (a == 1 && b == 1)
		cout << 0;
	else
	{
		if (b != 1)
		{
			for (int i = 1; i <= a; ++i)
			{
				for (int j = 1; j <= b; ++j)
					cout << i * (a + j) << ' ';
				cout << '\n';
			}
		}
		else
		{
			for (int j = 1; j <= a; ++j)
				cout << j + 1 << '\n';
		}
	}

	return 0;
}