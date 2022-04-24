//source: https://drive.google.com/file/d/1fUaI6mudYLqFC8slybAqDkfwzuqbj3c3/view
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("floyd.in");
ofstream fout("floyd.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

const int INF = 1000000000;

int main()
{
	int n; cin >> n;
	vector<vector<int>> Graph(n, vector<int>(n)), Dist; 
	for (auto& i : Graph) for (auto& j : i) cin >> j;
	Dist = Graph;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
	for (auto& i : Dist)
	{
		for (auto& j : i) cout << j << ' '; cout << '\n';
	}

	return 0;
}