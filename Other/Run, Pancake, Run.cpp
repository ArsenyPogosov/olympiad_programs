#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, k;
vector<vector<int>> graph;

vector<unordered_map<int, int>> respath, resloop;

int loopans(int v, int p = -1)
{
	if (resloop[v].find(p) != resloop[v].end()) return resloop[v][p];

	resloop[v][p] = 0;
	multiset<int> lmx;
	for (auto& i : graph[v])
		if (i != p)
			lmx.insert(loopans(i, v));

	resloop[v][p] = 0;
	for (int i = 0; i < k - 1; ++i)
	{
		if (!lmx.size()) break;
		resloop[v][p] += *prev(lmx.end()) + 2;
		lmx.erase(prev(lmx.end()));
	}

	return resloop[v][p];
}

int pathans(int v, int p = -1)
{
	if (respath[v].find(p) != respath[v].end()) return respath[v][p];

	respath[v][p] = 0;
	multiset<pair<int, int>> lmx, pmx;
	for (auto& i : graph[v])
		if (i != p)
		{
			lmx.emplace(loopans(i, v), i);
			if (lmx.size() > k)
			{
				pmx.emplace(pathans(lmx.begin()->second, v), lmx.begin()->second);
				lmx.erase(lmx.begin());
			}
		}

	pair<int, int> nbig;
	if (lmx.size() == k)
	{
		pmx.emplace(pathans(lmx.begin()->second, v), lmx.begin()->second);
		nbig = *lmx.begin(); lmx.erase(lmx.begin());
	}
	else
		nbig = { 0, -2 };

	pair<int, int> change{ -1, -1 };
	for (auto& i : lmx)
	{
		pair<int, int> t = { max(0, pathans(i.second, v) - loopans(i.second, v)), i.second };
		if (change < t)
			change = t;
	}

	int sum = 0;
	for (auto& i : lmx)
		sum += i.first;

	if (pmx.size())
		respath[v][p] = sum + prev(pmx.end())->first + lmx.size() * 2 + 1;
	respath[v][p] = max(respath[v][p], sum + change.first + nbig.first + (int)lmx.size() * 2 - 1 + (nbig.second != -2) * 2);

	return respath[v][p];
}

void loopansall(int v, int p = -1)
{
	multiset<pair<int, int>> lmx;
	for (auto& i : graph[v])
		{
			lmx.emplace(loopans(i, v), i);
			if (lmx.size() > k)
			{
				lmx.erase(lmx.begin());
			}
		}

	pair<int, int> nbig;
	if (lmx.size() == k)
	{
		nbig = *lmx.begin(); lmx.erase(lmx.begin());
	}
	else
		nbig = { 0, -2 };

	int sum = 0;
	for (auto& i : lmx)
		sum += i.first;

	resloop[v][-1] = sum + lmx.size() * 2;
	for (auto& i : graph[v])
		if (i != p)
		{
			resloop[v][i] = sum + lmx.size() * 2;
			if (lmx.find({ loopans(i, v), i }) != lmx.end())
				resloop[v][i] += -2 - loopans(i, v) + nbig.first + (nbig.second != -2) * 2;

			loopansall(i, v);
		}
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		graph.assign(n, vector<int>());
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b; --a; --b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		respath.assign(n, {});
		resloop.assign(n, {});

		loopans(0);
		loopansall(0);

		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			res = max(res, max(loopans(i), pathans(i)) * 10);
		}
		cout << res << '\n';
	}

	return 0;
}