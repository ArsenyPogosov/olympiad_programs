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

int n, N, M;
vector<vector<int>> Graph, f, check;

void brunch(int a, int b, int c)
{
	Graph[a][b] = c;
	check[a].push_back(b);
	check[b].push_back(a);
}

int num(int i, int j)
{
	return 1 + N + i * M + j;
}

bool relax()
{
	queue<int> Q; Q.push(0);
	vector<int> p(n, -1);
	while (Q.size())
	{
		int u = Q.front(); Q.pop();
		for (auto& v : check[u])
			if (p[v] == -1 && Graph[u][v] - f[u][v] > 0)
			{
				p[v] = u;
				Q.push(v);
			}
	}
	if (p[n - 1] == -1) return false;
	int d = 1e9 + 1, t = n - 1;
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
	cin >> N >> M;

	n = 1 + N + N * M + 1;
	Graph.resize(n, vector<int>(n));
	f.resize(n, vector<int>(n));
	check.resize(n);
	vector<int> a(N), b(M);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	vector<vector<int>> Z(N, vector<int>(M));
	for (auto& i : Z)
		for (auto& j : i)
			cin >> j;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Z[i][j] != -1)
			{
				a[i] -= Z[i][j];
				b[j] -= Z[i][j];
				if (a[i] < 0 || b[j] < 0)
				{
					cout << "-1\n";
					return 0;
				}
			}
	for (int i = 0; i < N; ++i)
		brunch(0, i + 1, a[i]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Z[i][j] == -1)
				brunch(i + 1, num(i, j), 1e9);
	for (int j = 0; j < M; ++j)
	{
		for (int i = 0; i < N - 1; ++i)
			brunch(num(i, j), num(i + 1, j), 1e9);
		brunch(num(N - 1, j), num(N - 1, M - 1) + 1, b[j]);
	}

	while (relax());
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Z[i][j] == -1)
				Z[i][j] = f[i + 1][num(i, j)];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cout << Z[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}