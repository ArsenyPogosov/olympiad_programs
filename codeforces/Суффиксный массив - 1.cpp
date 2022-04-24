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
	string s; cin >> s; s += '$';
	int n = s.size();
	vector<int> p(n), c(n);
	{
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; ++i) a[i] = { s[i], i };
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) p[i] = a[i].second;
		c[p[0]] = 0;
		for (int i = 1; i < n; ++i)
			c[p[i]] = c[p[i - 1]] + (a[i - 1].first != a[i].first);
	}
	int k = 0;
	while ((1 << k) < n && c[n - 1] != n - 1)
	{
		vector<pair<pair<int, int>, int>> a(n);
		for (int i = 0; i < n; ++i) a[i] = { {c[i], c[(i + (1 << k)) % n]}, i };
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) p[i] = a[i].second;
		c[p[0]] = 0;
		for (int i = 1; i < n; ++i)
			c[p[i]] = c[p[i - 1]] + (a[i - 1].first != a[i].first);
		++k;
	}
	for (auto& i : p) cout << i << ' ';

	return 0;
}