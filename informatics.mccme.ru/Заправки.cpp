#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<int> cost(n);
	for (auto&i : cost)
		fin >> i;
	int m;
	fin >> m;
	vector<list<int>> graph(n, list<int>({}));
	int a, b;
	for (int i = 0; i <= m - 1; ++i)
	{
		fin >> a >> b; --a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> fire(n, -1);
	fire[0] = 0;
	queue<int> Q;
	Q.push(0);
	while (!Q.empty())
	{
		for (auto&i : graph[Q.front()])
		{
			if (fire[i] > fire[Q.front()] + cost[Q.front()])
			{
				fire[i] = fire[Q.front()] + cost[Q.front()];
				Q.push(i);
			}
			if (fire[i] == -1)
			{
				fire[i] = fire[Q.front()] + cost[Q.front()];
				Q.push(i);
			}
		}

		Q.pop();
	}

	fout << fire[n - 1];

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}