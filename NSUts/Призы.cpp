//source: file:///C:/Users/arsen/Downloads/1%20(3).pdf
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int max1 = a[0], max2 = -1;
	for (int i = 1; i < n; ++i)
	{
		max2 = max(max2, a[i]);
		if (max1 < max2) swap(max1, max2);
		cout << max2 << ' ';
	}

	return 0;
}