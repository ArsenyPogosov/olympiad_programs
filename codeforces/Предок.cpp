//source: https://codeforces.com/gym/100083/attachments/download/1195/20122013-tryenirovka-spbgu-b-2-poisk-v-glubinu-ru.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("ancestor.in");
ofstream fout("ancestor.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<list<int>> Graph;
vector<int> tin, tout;
int t = 0;

void DFS(int v)
{
	tin[v] = ++t;

	for (auto& i : Graph[v])
		DFS(i);

	tout[v] = t++;
}

bool check(int u, int v)
{
	return (tin[u] < tin[v]) && (tout[v] < tout[u]);
}

int main()
{
	int n; cin >> n;
	Graph.resize(n); tin.resize(n); tout.resize(n);
	int root = -1;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		if (h == 0)
			root = i;
		else
			Graph[h - 1].push_back(i);
	}
	DFS(root);
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		cout << int(check(a - 1, b - 1)) << '\n';
	}

	return 0;
}