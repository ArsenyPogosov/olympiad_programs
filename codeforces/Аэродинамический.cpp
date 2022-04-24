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

bool check(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d)
{
	long long x1 = b.first - a.first, y1 = b.second - a.second;
	long long x2 = d.first - c.first, y2 = d.second - c.second;
	return (x1 * y2 - x2 * y1 == 0)&&(x1*x1+y1*y1==x2*x2+y2*y2);
}

int main()
{
	long long n; cin >> n;
	vector<pair<long long, long long>> node(n);
	for (auto& i : node) cin >> i.first >> i.second;
	if (n % 2 == 1)
	{
		cout << "no\n";
		return 0;
	}
	for (long long i = 0; i < n; ++i)
		if (!check(node[i], node[(i + 1) % n], node[(i + n / 2) % n], node[(i + n / 2 + 1) % n]))
		{
			cout << "no\n";
			return 0;
		}
	cout << "yes\n";

	return 0;
}