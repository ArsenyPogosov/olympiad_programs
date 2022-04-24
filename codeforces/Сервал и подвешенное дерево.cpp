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
vector<list<int>> Graph;
vector<int> reg, dp;

const int INF = 1000000000;

void DFS(int v)
{
	if (Graph[v].size() == 0) { dp[v] = 1; return; }
	if (reg[v] == 0)
	{
		dp[v] = 0;
		for (auto& i : Graph[v])
		{
			DFS(i);
			dp[v] += dp[i];
		}
	}
	if (reg[v] == 1)
	{
		dp[v] = INF;
		for (auto& i : Graph[v])
		{
			DFS(i);
			dp[v] = min(dp[v], dp[i]);
		}
	}
}

int main()
{
	cin >> n;
	Graph.resize(n); reg.resize(n);
	for (auto& i : reg) cin >> i;
	for (int i = 1; i < n; ++i)
	{
		int a; cin >> a; Graph[a - 1].push_back(i);
	}
	dp.resize(n);
	DFS(0);
	int count = 0;
	for (auto& i : Graph)
		if (i.size() == 0)
			++count;

	cout << count - dp[0] + 1;

	return 0;
}