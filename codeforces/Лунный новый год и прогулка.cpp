//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258385/problems
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
	int n, m;
	cin >> n >> m;
	vector<list<int>> g(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y; --x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	set<int> d;
	d.insert(0);
	vector<char> used(n);
	used[0] = 1;
	while (!d.empty())
	{
		int v = *d.begin();
		d.erase(d.begin());
		used[v] = true;
		cout << v + 1 << ' ';
		for (auto& i : g[v]) if (!used[i]) d.insert(i);
	}

	return 0;
}