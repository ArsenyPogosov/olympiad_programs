#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> fire;
vector<int> graph;

void DFS(int v)
{
	fire[v] = 1;
	if (fire[graph[v]] == 0)
		DFS(graph[v]);
	fire[v] = 2;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<bool> callHim(n, true);
	graph = vector<int>(n, 0);
	fire = vector<int>(n, 0);
	for (int i = 0; i <= n - 1; ++i)
	{
		int h;
		fin >> h; --h;
		graph[i] = h;
		callHim[h] = false;
	}

	int ans = 0;
	for (int i = 0; i <= n - 1; ++i)
		if (callHim[i])
		{
			++ans;
			DFS(i);
		}

	for (int i = 0; i <= n - 1; ++i)
		if (fire[i] == 0)
		{
			++ans;
			DFS(i);
		}

	fout << ans;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}