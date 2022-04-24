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
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	vector<int> count(33);
	for (auto& i : a)
	{
		int h = i;
		int c = 0;
		while (h > 0)
		{
			if (h % 2 == 1) ++count[c];
			h /= 2;
			++c;
		}
	}
	int best = -1, tbest = -1;
	for (int i = 0; i < n; ++i)
	{
		int h = a[i];
		int c = 0;
		int tek = 0;
		while (h > 0)
		{
			if (h % 2 == 1 && (count[c] - 1 == 0)) tek += (1 << c);
			h /= 2;
			++c;
		}
		if (tek > tbest)
		{
			best = i;
			tbest = tek;
		}
	}
	cout << a[best] << ' ';
	for (int i = 0; i < n; ++i)
		if (i != best)
			cout << a[i] << ' ';

	return 0;
}