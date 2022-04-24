#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
#include <unordered_set>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<unordered_set<int>> Graph, UntiGraph;
vector<vector<int>> CompStrongConn;

void DFS(int v, vector<int>& TopSort, vector<bool>& used)
{
	if (used[v])
		return;
	used[v] = true;
	for (auto&i : Graph[v]) {
		if (!used[i])
			DFS(i, TopSort, used);
	}

	TopSort.push_back(v);
}

void DFS2(int v, vector<int>& Comp, vector<bool>& used)
{
	if (used[v])
		return;
	used[v] = true;
	for (auto&i : UntiGraph[v]) {
		if (!used[i])
			DFS2(i, Comp, used);
	}

	Comp.push_back(v);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	Graph.resize(n);
	UntiGraph.resize(n);
	{
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			fin >> a >> b; --a; --b;
			Graph[a].insert(b);
			UntiGraph[b].insert(a);
		}
	}
	{
		vector<int> TopSort;
		{
			vector<bool> used(n);
			for (int i = 0; i < n; ++i) {
				DFS(i, TopSort, used);
			}
		}
		reverse(TopSort.begin(), TopSort.end());
		{
			vector<int> component;
			vector<bool> used(n);
			for (auto&i : TopSort) {
				component.clear();
				DFS2(i, component, used);
				if (component.size() > 0) {
					CompStrongConn.push_back(component);
				}
			}
		}
	}

	vector<int> WhoUse(n);
	for (int i = 0; i < CompStrongConn.size(); ++i) {
		for (auto&j : CompStrongConn[i]) {
			WhoUse[j] = i;
		}
	}

	fout << CompStrongConn.size() << '\n';
	for (int i = 0; i < n; ++i) {
		fout << WhoUse[i] + 1 << ' ';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}