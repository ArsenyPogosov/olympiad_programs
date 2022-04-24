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

int GG(int a, int b)
{
	return (b == 0 ? a : GG(b, a % b));
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < GG(n, m); ++i) cout << 1;

	return 0;
}