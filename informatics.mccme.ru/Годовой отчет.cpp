//source: 
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

int n;
vector<vector<int>> Graph, f, check;

bool relax()
{
	queue<int> Q; Q.push(0);
	vector<int> p(n, -1);
	while (Q.size())
	{
		int u = Q.front(); Q.pop();
		for (auto& v: check[u])
			if (p[v] == -1 && (Graph[u][v] - f[u][v] > 0))
			{
				p[v] = u;
				Q.push(v);
			}
	}
	if (p[n - 1] == -1) return 0;

	int d = 1e9, t = n - 1;
	while (t > 0)
	{
		d = min(d, Graph[p[t]][t] - f[p[t]][t]);
		t = p[t];
	}
	t = n - 1;
	while (t > 0)
	{
		f[p[t]][t] += d;
		f[t][p[t]] -= d;
		t = p[t];
	}
	return true;
}

int main()
{
	cin >> n; n += 2;
	Graph.resize(n, vector<int>(n));
	f.resize(n, vector<int>(n));
	check.resize(n);
	for (int i = 1; i < n - 1; ++i)
	{
		int h; cin >> h;
		if (h == 1)
		{
			Graph[0][i] = 1001;
			check[0].push_back(i);
			check[i].push_back(0);
		}
		if (h == 2)
		{
			Graph[i][n - 1] = 1001;
			check[i].push_back(n - 1);
			check[n - 1].push_back(i);
		}
	}
	for (int i = 1; i < n - 1; ++i)
		for (int j = 1; j < n - 1; ++j)
		{
			cin >> Graph[i][j];
			if (Graph[i][j] != 0)
			{
				check[i].push_back(j);
				check[j].push_back(i);
			}
		}

	while (relax());
	int s = 0;
	for (auto& i : f[0]) s += i;
	cout << s << '\n';

	return 0;
}