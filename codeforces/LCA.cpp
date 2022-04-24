//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260272/problem/C
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

vector<vector<int>> up(30, vector<int>(5 * 100000 + 2));
vector<int> d(5 * 100000 + 2);

void add(int a, int b)
{
	d[b] = d[a] + 1;
	up[0][b] = a;
	for (int i = 1; i < 30; ++i)
		up[i][b] = up[i - 1][up[i - 1][b]];
}

int LA(int a, int k)
{
	int i = 29;
	while (k > 0)
	{
		if (k >= (1 << i))
		{
			a = up[i][a];
			k -= (1 << i);
		}
		--i;
	}
	return a;
}

int LCA(int a, int b)
{
	if (d[a] < d[b]) swap(a, b);
	a = LA(a, d[a] - d[b]);
	if (a == b) return a;
	for (int i = 29; i >= 0; --i)
		if (up[i][a] != up[i][b])
		{
			a = up[i][a];
			b = up[i][b];
		}
	return up[0][a];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k; cin >> k;
	for (int i = 0; i < k; ++i)
	{
		string s; int a, b; cin >> s >> a >> b;
		if (s == "ADD") add(a - 1, b - 1);
		if (s == "GET") cout << LCA(a - 1, b - 1) + 1 << '\n';
	}
	return 0;
}