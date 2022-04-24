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
	int n, k; cin >> n >> k;
	vector<int> x(n);
	for (auto& i : x) {
		char h; cin >> h; i = h - '0';
	}
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (x[i] < x[i % k])
			break;
		if (x[i] > x[i % k])
		{
			flag = false;
			break;
		}
	}
	if (!flag)
	{
		int it = k - 1; ++x[it];
		while (x[it] > 9)
		{
			x[it--] = 0;
			++x[it];
		}
	}
	cout << n << '\n';
	for (int i = 0; i < n; ++i)
		cout << x[i % k];

	return 0;
}