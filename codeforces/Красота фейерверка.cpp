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

int main()
{
	long long n, m; cin >> n >> m;
	vector<vector<long long>> Graph(n);
	for (long long i = 1; i < n; ++i)
	{
		long long v; cin >> v; --v;
		Graph[i].push_back(v);
		Graph[v].push_back(i);
	}
	queue<long long> Q; Q.push(0);
	vector<long long> fire(n, 1e9); fire[0] = 0;
	while (Q.size())
	{
		long long v = Q.front(); Q.pop();
		for (auto& u : Graph[v])
			if (fire[u] == 1e9)
			{
				fire[u] = fire[v] + 1;
				Q.push(u);
			}
	}
	long long bl = 1;
	for (long long i = 2; i < n; ++i)
		if (fire[bl] < fire[i])
			bl = i;
	long long r = fire[bl];

	Q.push(bl);
	fire.assign(n, 1e9); fire[bl] = 0;
	while (Q.size())
	{
		long long v = Q.front(); Q.pop();
		for (auto& u : Graph[v])
			if (fire[u] == 1e9)
			{
				fire[u] = fire[v] + 1;
				Q.push(u);
			}
	}
	long long d = -1;
	for (long long i = 0; i < n; ++i)
		d = max(d, fire[i]);
	
	cout << d + (r + 1) * (m - 1) * 2 + 1 << '\n';

	return 0;
}