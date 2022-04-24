#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

vector<int> parent, ranc;

int get(int v)
{
	if (parent[v] == v)
		return v;

	return parent[v] = get(parent[v]);
}

void merge(int v, int u)
{
	v = get(v);
	u = get(u);
	if (ranc[v] > ranc[u])
		swap(v, u);
	parent[v] = u;
	if (ranc[v] == ranc[u])
		++ranc[u];
}

bool equal(int v, int u)
{
	return get(v) == get(u);
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
	}
	parent.resize(n);
	for (int i = 0; i < n; ++i)
		parent[i] = i;
	ranc.resize(n);
	vector<vector<int>> move;
	move.reserve(k);
	set<vector<int>> kd;
	for (int i = 0; i < k; ++i)
	{
		move.push_back({ 0, 0, 0 });
		while (true)
		{
			string s;
			cin >> s >> move[i][1] >> move[i][2];
			--move[i][1];
			--move[i][2];
			if (s == "ask")
				move[i][0] = 0;
			else
				move[i][0] = 1;
			if ((move[i][0] == 0) || (kd.find(move[i]) == kd.end()))
				break;
		}
		if (move[i][0] == 1)
			kd.insert(move[i]);
	}
	reverse(move.begin(), move.end());
	list<string> res;
	for (auto&i : move)
	{
		if (i[0] == 0)
		{
			if (equal(i[1], i[2]))
				res.push_front("YES\n");
			else
				res.push_front("NO\n");
		}
		else
			merge(i[1], i[2]);
	}
	for (auto&i : res)
		cout << i;

	return 0;
}