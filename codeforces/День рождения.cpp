//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/D
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("birthday.in");
ofstream fout("birthday.out");
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

vector<int> mused, wused;
void FDFS(int v)
{
	if (mused[v]) return;
	mused[v] = true;
	for (auto& i : Graph[v])
	{
		if (p[i] != -1 && !wused[i])
			FDFS(p[i]);
		wused[i] = true;
	}
}

int main()
{
	int kkk; cin >> kkk;
	for (int kkkk = 0; kkkk < kkk; ++kkkk)
	{
		cin >> n >> m; Graph.assign(n, {});
		for (auto& i : Graph)
		{
			int h; cin >> h;
			vector<int> was(m);
			while (h)
			{
				was[h - 1] = true;
				cin >> h;
			}
			for (int j = 0; j < m; ++j)
				if (!was[j])
					i.push_back(j);
		}

		p.assign(m, -1); used.assign(n, -1);
		for (int i = 0; i < n; ++i)
			if (DFS(i))
				++T;

		mused.assign(n, false); wused.assign(m, false);
		vector<int> sp(n, true);
		for (int i = 0; i < m; ++i) if (p[i] >= 0) sp[p[i]] = false;
		for (int i = 0; i < n; ++i)
			if (sp[i])
				FDFS(i);
		list<int> M, W;
		for (int i = 0; i < n; ++i)
			if (mused[i])
				M.push_back(i);
		for (int i = 0; i < m; ++i)
			if (!wused[i])
				W.push_back(i);
		cout << M.size() + W.size() << '\n' << M.size() << ' ' << W.size() << '\n';
		for (auto& i : M) cout << i + 1 << ' ';
		cout << '\n';
		for (auto& i : W) cout << i + 1 << ' ';
		cout << '\n' << '\n';
	}

	return 0;
}