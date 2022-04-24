//source: https://codeforces.com/contest/1237/problem/B
//status: solved

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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<char> w(n + 1, 0);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	int count = 0, bi = 0;
	for (int ai = 0; ai < n; ++ai)
		if (w[a[ai]] == 0)
		{
			while (a[ai] != b[bi])
			{
				++count;
				w[b[bi++]] = 1;
			}
			++bi;
		}
	cout << count;

	return 0;
}