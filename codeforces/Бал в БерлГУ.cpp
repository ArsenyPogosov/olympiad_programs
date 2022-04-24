//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/A
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

int n, m;
vector<list<int>> Graph;
vector<int> p, used;
int T = 0;

bool DFS(int v)
{
	if (used[v] == T) return false;
	used[v] = T;
	for (auto& i : Graph[v])
		if (p[i] == -1 || DFS(p[i]))
		{
			p[i] = v;
			return true;
		}
	return false;
}

int main()
{
	cin >> n; 
	Graph.resize(n);
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	cin >> m;
	vector<int> b(m);
	for (auto& i : b) cin >> i;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (abs(a[i] - b[j]) <= 1)
				Graph[i].push_back(j);
	p.resize(m, -1); used.resize(n, -1);
	for (int i = 0; i < n; ++i)
		if (DFS(i))
			++T;
	int count = 0;
	for (int i = 0; i < m; ++i)
		if (p[i] >= 0)
			++count;
	cout << count << '\n';
	
	return 0;
}