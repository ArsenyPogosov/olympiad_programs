#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<int>> Graph;
vector<int> Parents;

void DFS(int v, int parent = -1)
{
	Parents[v] = parent;
	for (auto&u : Graph[v]) {
		if (Parents[u] == -1) DFS(u, v);
	}
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
	Parents.resize(n, -1);
	DFS(0);
	for (int i = 1; i < n; ++i)
		fout << i + 1 << ' ' << Parents[i] + 1<< '\n';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}