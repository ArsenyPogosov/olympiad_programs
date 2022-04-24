#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<int>> Graph;
vector<int> Ans;

void DFS(int v, int k, vector<bool>& used)
{
	used[v] = true;
	vector<int> ToSort;
	for (auto&i : Graph[v]) {
		if (!used[i]) {
			DFS(i, k, used);
			ToSort.push_back(Ans[i]);
		}
	}
	if (ToSort.size() >= k)
	{
		sort(ToSort.begin(), ToSort.end());
		Ans[v] = ToSort[ToSort.size() - k] + 1;
	}
}

int main()
{
	int n; cin >> n;
	Graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	for (int k = 1; k <= n; ++k)
	{
		Ans = vector<int>(n, 1);
		vector<bool> used(n);
		DFS(0, k, used);
		int maxxx{ 0 };
		for (auto&i : Ans)
			maxxx = max(maxxx, i);
		cout << maxxx << ' ';
	}

	return 0;
}