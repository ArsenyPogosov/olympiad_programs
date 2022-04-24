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
	long long a, b, c;
	cin >> a >> b >> c;
	long long A = a * 2 + b * 3 + c * 4, B = a + b + c;
	cout << max(0LL, (7 * B - 2 * A + 2) / 3);

	return 0;
}