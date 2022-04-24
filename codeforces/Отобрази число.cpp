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
	while (t--)
	{
		int n; cin >> n;
		if (n % 2 == 1)
		{
			cout << 7;
			n -= 3;
		}
		else
		{
			cout << 1;
			n -= 2;
		}
		for (int i = 0; i < n / 2; ++i)
			cout << 1;
		cout << '\n';	
	}

	return 0;
}