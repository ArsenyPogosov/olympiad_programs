//source: http://neerc.ifmo.ru/school/io/archive/20191019/problems-20191019-advanced.pdf
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
	 long long n;
	cin >> n;
	vector<pair< long long,  long long>> table(n);
	for (auto& i : table) cin >> i.first >> i.second;
	 long long m;
	cin >> m;
	for ( long long i = 0; i < m; ++i)
	{
		 long long h;
		cin >> h;
		cout << (lower_bound(table.begin(), table.end(), pair< long long,  long long>{h, -1})-1)->second* h << '\n';
	}

	return 0;
}