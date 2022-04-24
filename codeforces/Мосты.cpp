//source: https://codeforces.com/gym/100083/attachments/download/1195/20122013-tryenirovka-spbgu-b-2-poisk-v-glubinu-ru.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("bridges.in");
ofstream fout("bridges.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<list<pair<int, int>>> Graph;
vector<int> fire, D;
set<int> bridge;

void DDFS(int v, int d = 0)
{
	D[v] = d;
	fire[v] = true;
	for (auto& i : Graph[v])
		if (!fire[i.first])
			DDFS(i.first, d + 1);
}

int BDFS(int v, int ind = -1)
{
	int Dup = D[v];
	fire[v] = true;
	for (auto& i : Graph[v])
		if (i.second != ind)
		{
			if (!fire[i.first])
			{
				int Dupi = BDFS(i.first, i.second);
				Dup = min(Dup, Dupi);
				if (Dupi > D[v])
					bridge.insert(i.second);
			}
			else
				Dup = min(Dup, D[i.first]);
		}

	return Dup;
}

int main()
{
	int n, m; cin >> n >> m;
	Graph.resize(n); fire.resize(n); D.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		Graph[a].push_back({ b, i });
		Graph[b].push_back({ a, i });
	}

	for (int i = 0; i < n; ++i)
		if (!fire[i])
			DDFS(i); 

	fire.assign(n, 0);
	for (int i = 0; i < n; ++i)
		if (!fire[i])
			BDFS(i);

	cout << bridge.size() << '\n';
	for (auto& i : bridge) cout << i + 1 << ' ';

	return 0;
}