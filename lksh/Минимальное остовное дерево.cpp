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

bool merge(int v, int u)
{
	v = get(v);
	u = get(u);
	if (v == u)
		return false;

	if (ranc[v] > ranc[u])
		swap(v, u);
	parent[v] = u;
	if (ranc[v] == ranc[u])
		++ranc[u];
	return true;
}

bool equal(int v, int u)
{
	return get(v) == get(u);
}

int main()
{
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> e(m, vector<long long>(3));
	for (auto&i : e)
		cin >> i[1] >> i[2] >> i[0];
	sort(e.begin(), e.end());
	parent.resize(n);
	for (int i = 0; i < n; ++i)
		parent[i] = i;
	ranc.resize(n);
	long long weight = 0;
	int count = 0;
	for (int i = 0; i < m && count < n - 1; ++i)
		if (merge(e[i][1] - 1, e[i][2] - 1))
		{
			--count;
			weight += e[i][0];
		}
	cout << weight;

	return 0;
}