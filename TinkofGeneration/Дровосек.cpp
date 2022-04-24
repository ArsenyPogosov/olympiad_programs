#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n, root;
vector<vector<pair<long long, long long>>> graph;

vector<long long> res;

void DFS(long long v, long long p = -1)
{
	res[v] = 0;
	for (auto& i : graph[v])
		if (i.first != p)
		{
			DFS(i.first, v);
			res[v] ^= res[i.first] + 1;
		}
}

long long win(long long v, long long p, long long targ)
{
	for (auto& i : graph[v])
		if (i.first != p)
			if (((res[i.first] + 1) ^ res[v] ^ targ) < (res[i.first] + 1))
			{
				long long ntarg = ((res[i.first] + 1) ^ res[v] ^ targ);
				if (!ntarg)
					return i.second;
				return win(i.first, v, ntarg - 1);
			}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> root; --root;
	graph.resize(n);
	for (long long i = 0; i < n - 1; ++i)
	{
		long long a, b; cin >> a >> b; --a; --b;
		graph[a].emplace_back(b, i);
		graph[b].emplace_back(a, i);
	}

	res.resize(n);
	DFS(root);

	if (res[root])
		cout << 1 << '\n' << win(root, -1, 0) + 1 << '\n';
	else
		cout << 2 << '\n';

	return 0;
}