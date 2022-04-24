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
vector<long long> Time;
vector<int> used;
vector<int> ans;
long long TimeAns;

void DFS(int v)
{
	used[v] = true;
	TimeAns += Time[v];
	for (auto&u : Graph[v]) {
		if (!used[u]) DFS(u);
	}
	ans.push_back(v);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	Graph.resize(n);
	{
		Time.resize(n);
		for (int i = 0; i < n; ++i)
			fin >> Time[i];

		for (int i = 0; i < n; ++i)
		{
			int m;
			fin >> m;
			for (int j = 0; j < m; ++j)
			{
				int a;
				fin >> a;
				Graph[i].push_back(a - 1);
			}
		}
	}
	used.resize(n);
	TimeAns = 0;
	DFS(0);
	fout << TimeAns  << ' ' << ans.size() << '\n';
	for (auto&i : ans) {
		fout << i + 1 << ' ';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}