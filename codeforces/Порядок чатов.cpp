//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258385/problems
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
	vector<string> v(n);
	for (auto& i : v) cin >> i;
	unordered_map<string, bool> w;
	for (int i = n - 1; i >= 0; --i)
		if (!w[v[i]]) { cout << v[i] << '\n'; w[v[i]] = true; }

	return 0;
}