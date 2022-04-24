//source: https://informatics.msk.ru/mod/statements/view.php?id=43886#1
//status: solved

#include <bits/stdc++.h>
using namespace std;
#define f_io
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
	int k, x1 = 1000000001, x2 = -1000000001, y1 = 1000000001, y2 = -1000000001;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b;
		cin >> a >> b;
		x1 = min(x1, a);
		x2 = max(x2, a);
		y1 = min(y1, b);
		y2 = max(y2, b);
	}
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;

	return 0;
}