//source: https://codeforces.com/gym/102348/problem/D
//status: solved

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
	int count1 = 0, count2 = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		char h;
		cin >> h;
		count1 += h != '?' ? (h - '0') * 2 - 9 : 0;
	}
	for (int i = 0; i < n / 2; ++i)
	{
		char h;
		cin >> h;
		count2 += h != '?' ? (h - '0') * 2 - 9 : 0;
	}
	if (count1 != count2)
		cout << "Monocarp";
	else
		cout << "Bicarp";

	return 0;
}