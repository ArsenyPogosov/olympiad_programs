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
	int t; cin >> t;
	for (int tt = 0; tt < t; ++tt)
	{
		int n; cin >> n;
		set<int> res;
		for (int i = 0; i * i <= n; ++i) res.insert(i);
		for (int y = 40000; y > 0; --y) res.insert(n / y);
		cout << res.size() << '\n';
		for (auto& i : res) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}