#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> rgraph, tgraph;
string st(int a, int b, int c)
{
	return to_string(min({ a, b, c })) + to_string(a + b + c - min({ a, b, c }) - max({ a, b, c })) + to_string(max({ a, b, c }));
}

vector<string> trant(int a, int b)
{
	if (rgraph[a].size() > rgraph[b].size()) swap(a, b);

	auto it = rgraph[b].begin();
	vector<string> res;
	for (auto& i : rgraph[a])
	{
		it = lower_bound(it, rgraph[b].end(), i);
		if (it == rgraph[b].end()) return res;
		if (*it == i) res.push_back(st(a, b, i));
	}

	return res;
}

void eraseab(int a, int b)
{
	vector<int> nv;
	for (auto& i : tgraph[a])
		if (i != b) nv.push_back(i);
	tgraph[a] = nv;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; rgraph.resize(n), tgraph.resize(n - 2);
	for (int i = 0; i < n; ++i)
	{
		rgraph[i].push_back((i + 1) % n);
		rgraph[(i + 1) % n].push_back(i);
	}
	for (int i = 0; i < n - 3; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		rgraph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	for (auto& i : rgraph) sort(i.begin(), i.end());

	int t = 1;
	map<string, int> tnum;
	for (int i = 0; i < n; ++i)
		for (auto& j : rgraph[i])
			if (i < j)
			{
				vector<string> res = trant(i, j);
				for (auto& i : res)
					if (!tnum[i]) tnum[i] = t++;
				if (res.size() == 2)
				{
					int a = tnum[res[0]] - 1, b = tnum[res[1]] - 1;
					tgraph[a].push_back(b);
					tgraph[b].push_back(a);
				}
			}

	int res = 0;
	vector<char> del(n - 2, false);
	queue<int> Q;
	for (int i = 0; i < n - 2; ++i)
	{
		if (tgraph[i].size() == 0)
			++res;
		if (tgraph[i].size() == 1)
			Q.push(i);
	}
	while (Q.size())
	{
		int v = Q.front(); Q.pop();
		if (del[v]) continue;
		del[v] = true; ++res;
		if (tgraph[v].size() == 0) continue;
		int u = tgraph[v][0];
		del[u] = true;
		eraseab(u, v);
		for (auto& i : tgraph[u])
		{
			eraseab(i, u);
			if (tgraph[i].size() < 2)
				Q.push(i);
		}
	}
	cout << res << '\n';

	return 0;
}