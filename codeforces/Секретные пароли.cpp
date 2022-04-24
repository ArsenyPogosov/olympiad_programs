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

int alp = 'z' - 'a' + 1;

vector<int> fire;
vector<vector<int>> Graph;

void dfs(int v)
{
	fire[v] = true;
	for (auto& i : Graph[v])
		if (!fire[i])
			dfs(i);
}

int main()
{
	int n; cin >> n;
	Graph.resize(n + alp);
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		vector<int> was(alp);
		for (auto&j: s)
			if (!was[j -'a'])
			{
				was[j - 'a'] = true;
				Graph[i].push_back(n + j - 'a');
				Graph[n + j - 'a'].push_back(i);
			}
	}
	int count = 0;
	fire.resize(n + alp);
	for (int i = 0; i < n; ++i)
		if (!fire[i])
		{
			++count;
			dfs(i);
		}
	cout << count;

	return 0;
}