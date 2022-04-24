//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258319/attachments/download/6442/statements.pdf
//status: coding

#include <bits/stdc++.h>
#include <unordered_map>
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
	int maxx = -1;
	unordered_map<int, int> m;
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;
		++m[h];
	}
	for (auto& i : m)
		maxx = max(maxx, i.second);
	cout << min(n, (n - maxx) *  2 + 1);

	return 0;
}