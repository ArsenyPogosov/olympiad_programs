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
	long long n; cin >> n;
	vector<int> oc(n * 2 + 5, 0);
	for (int i = 0; i < n; ++i)
	{
		int l, r; cin >> l >> r;
		oc[l] = i; oc[r] = -i;
	}
	int cl = 0, cr = 0;
	vector<int> wl(n, 0), wr;
	for (int i = 0; i < n * 2 + 5; ++i)
	{
		if (oc[i] > 0)
		{
			++cl;
		}
		if (oc[i] < 0)
		{
			++cr;
		}
		wl[i] = cl;
		wr[i] = cr;
	}
	if (b == n - 1)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}