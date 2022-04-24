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
	vector<vector<int>> c;
	double x = clock();
	for (int i = 0; i < 10000; ++i)
		c.emplace_back(10000, i);
	cout << (clock() - x) / CLOCKS_PER_SEC << "\n\n";
	vector<vector<int>> b;
	double a = clock();
	for (int i = 0; i < 10000; ++i)
		b.push_back(vector<int>(10000, i));
	cout << (clock() - a) / CLOCKS_PER_SEC;

	return 0;
}