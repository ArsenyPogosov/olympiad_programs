//source: 
//status: coding

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
	long long n, k, t, m;
	cin >> n >> k >> t; m = k * min(t, 1000000000000/k + 1);
	vector<long long> b(n);
	for (auto& i : b)
	{
		char h1, h2, h3;
		cin >> h1 >> h2 >> h3;
		i = (h1 - '0') * 100 + (h2 - '0') * 10 + (h3 - '0') * 1;
		cin >> h1 >> h1 >> h2 >> h3;
		i *= (h1 - '0') * 100 + (h2 - '0') * 10 + (h3 - '0') * 1;
	}
	sort(b.begin(), b.end());
	long long sum = 0, i;
	for(i = 0; i < n; ++i)
	{
		sum += b[i];
		if (sum > m) { --i; break; }
	}
	if (i >= n) i = n - 1;
	cout << i + 1;

	return 0;
}