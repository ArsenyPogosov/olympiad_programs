//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258319/attachments/download/6442/statements.pdf
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

vector<list<int>> Graph;
vector<int> fire;

void DFS(int v)
{
	fire[v] = true;
	for (auto& i : Graph[v])
		if (!fire[i])
			DFS(i);
}

int main()
{
	int n, m;
	cin >> n >> m;
	Graph.resize(n);
	vector<int> baze(n);
	for (auto& i : baze) cin >> i;
	for (int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y; --x; --y;
		if (baze[x] != baze[y])
		{
			Graph[x].push_back(y);
			Graph[y].push_back(x);
		}
	}
	fire.resize(n);
	DFS(0);
	for (auto& i : fire)
		if (!i)
		{
			cout << "NO";
			return 0;
		}
	cout << "YES";

	return 0;
}