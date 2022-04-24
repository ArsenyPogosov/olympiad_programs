//source: https://codeforces.com/contest/1225/problem/A
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
	int da, db;
	cin >> da >> db;
	if (da == db)
		cout << da * 10 << ' ' << da * 10 + 1;
	else
	{
		if (da + 1 == db || (da == 9 && db == 1))
			cout << da * 10 + 9 << ' ' << da * 10 + 10;
		else
		{
			cout << -1;
		}
	}

	return 0;
}