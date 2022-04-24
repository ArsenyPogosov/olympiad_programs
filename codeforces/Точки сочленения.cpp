//source: https://codeforces.com/gym/100083/attachments/download/1195/20122013-tryenirovka-spbgu-b-2-poisk-v-glubinu-ru.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("points.in");
ofstream fout("points.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<list<pair<int, int>>> Graph;
vector<int> fire, D;
set<int> artp;

void DDFS(int v, int d = 0)
{
	D[v] = d;
	fire[v] = true;
	for (auto& i : Graph[v])
		if (!fire[i.first])
			DDFS(i.first, d + 1);
}

int ADFS(int v, int ind = -1)
{
	int Dup = D[v];
	fire[v] = true;
	int count = 0;
	for (auto& i : Graph[v])
		if (i.second != ind)
		{
			if (!fire[i.first])
			{
				++count;
				int Dupi = ADFS(i.first, i.second);
				Dup = min(Dup, Dupi);
				if (Dupi >= D[v] && ind != -1)
					artp.insert(v);
			}
			else
				Dup = min(Dup, D[i.first]);
		}
	if (count > 1 && ind == -1) artp.insert(v);

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
			ADFS(i);

	cout << artp.size() << '\n';
	for (auto& i : artp) cout << i + 1 << ' ';

	return 0;
}