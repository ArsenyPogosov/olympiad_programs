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
	int a, b; cin >> a >> b;
	vector<string> N(a), M(b);
	for (auto& i : N) cin >> i;
	for (auto& i : M) cin >> i;
	int q; cin >> q;
	while (q--)
	{
		int n; cin >> n;
		cout << N[(n - 1) % a] << M[(n - 1) % b] << '\n';
	}

	return 0;
}