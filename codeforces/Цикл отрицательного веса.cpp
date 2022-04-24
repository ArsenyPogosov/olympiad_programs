//source: https://drive.google.com/file/d/1fUaI6mudYLqFC8slybAqDkfwzuqbj3c3/view
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
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
	int n; cin >> n;
	vector<vector<int>> Graph(n, vector<int>(n));
	for (auto& i : Graph) for (auto& j : i) cin >> j;
	vector<vector<int>> Dist

	return 0;
}