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
	long long n, k; cin >> n >> k;
	long long tek = n - 1;
	long long count = 0;
	while (tek % k != k - 1)
	{
		if (tek + 1 < k)
		{
			cout << "0\n";
			return 0;
		}
		++count;
		tek -= tek / k;
	}
	cout << count + 1<< '\n';

	return 0;
}