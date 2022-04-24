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
vector<bool> used;
vector<int> carriage;
bool AllIsBad{ false };

void DFS(int v, int parent = -1)
{
	used[v] = true;
	if (parent == -1)
		carriage[v] = 0;
	else
		carriage[v] = (carriage[parent] + 1) % 2;

	for (auto&u : Graph[v]) {
		if (!used[u]) {
			DFS(u, v);
			if (AllIsBad) return;
		}
		else
			if (carriage[v] == carriage[u]) {
				AllIsBad = true; // ALL IS BADDD!!!
				return;
			}
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

	used.resize(n);
	carriage.resize(n);
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			DFS(i);
			if (AllIsBad) break;
		}
	}
	if (AllIsBad) fout << 0;
	else {
		for (int i = 0; i < n; ++i) {
			if (carriage[i] == 0)
				fout << i + 1 << ' ';
		}
		fout << '\n';
		for (int i = 0; i < n; ++i) {
			if (carriage[i] == 1)
				fout << i + 1 << ' ';
		}
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}