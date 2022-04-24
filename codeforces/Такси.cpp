//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/A
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("taxi.in");
ofstream fout("taxi.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int n, m;
vector<list<int>> Graph;
vector<int> p, used;
int T = 0;

struct order
{
	int time, a, b, c, d;
	order() {};
};

void Read(order& o)
{
	string s; cin >> s;
	o.time = atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
	cin >> o.a >> o.b >> o.c >> o.d;
}

vector<order> Ord;

bool br(order x, order y)
{
	return x.time + abs(x.c - x.a) + abs(x.d - x.b) + abs(y.a - x.c) + abs(y.b - x.d) < y.time;
}

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
	cin >> n; m = n;
	Ord.resize(n);
	for (auto& i : Ord) Read(i);
	Graph.resize(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j && br(Ord[i], Ord[j]))
				Graph[i].push_back(j);

	p.resize(m, -1); used.resize(n, -1);
	for (int i = 0; i < n; ++i)
		if (DFS(i))
			++T;

	int count = 0;
	for (int i = 0; i < m; ++i)
		if (p[i] >= 0)
			++count;
	cout << n - count << '\n';
	
	return 0;
}