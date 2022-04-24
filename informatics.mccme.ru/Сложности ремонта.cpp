#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> ThatPoints;
vector<int> Fup;
vector<bool> used;
vector<int> depth;
vector<vector<int>> Graph;

void DFS(int v, int parent = -1)
{
	if (parent == -1)
		depth[v] = 0;
	else
		depth[v] = depth[parent] + 1;
	used[v] = true;
	Fup[v] = depth[v];
	bool flag{ parent != -1 };
	int count{ 0 };
	for (auto&u : Graph[v])
	{
		if (u == parent)
			continue;
		if (!used[u])
		{
			++count;
			DFS(u, v);
			Fup[v] = min(Fup[v], Fup[u]);
			if ((Fup[u] >= depth[v]) && (flag)) {
				ThatPoints.push_back(v);
				flag = false;
			}

		}
		else
			Fup[v] = min(Fup[v], depth[u]);
	}
	if (parent == -1)
		if (count > 1)
			ThatPoints.push_back(v);
}
int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	Graph.resize(n);
	{
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			fin >> a >> b; --a; --b;
			Graph[a].push_back(b);
			Graph[b].push_back(a);
		}
	}
	Fup.resize(n, 1000000000);
	used.resize(n);
	depth.resize(n);
	DFS(0);
	fout << ThatPoints.size() << '\n';
	sort(ThatPoints.begin(), ThatPoints.end());
	for (auto&i : ThatPoints)
		fout << i + 1 << '\n';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}