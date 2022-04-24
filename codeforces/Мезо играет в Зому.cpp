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
	int n; 
	cin >> n;
	for (int i = 0; i < n; ++i) { char h; cin >> h; }
	cout << n + 1;

	return 0;
}