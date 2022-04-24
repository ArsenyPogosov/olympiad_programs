#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

const int INF = 1000000000;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<list<pair<int, int>>> Graph(n, list<pair<int, int>>(0, {0, 0}));
	int h;
	for (auto&i: Graph)
		for (int j = 0; j <= n - 1; ++j)
		{
			fin >> h;
			if (h != 0)
				i.push_back({ j, h });
		}

	int maxxx{ 0 };
	queue<int> Q;
	vector<int> fire;
	for (int i = 0; i <= n - 1; ++i)
	{
		fire = vector<int>(n, INF);
		fire[i] = 0;
		Q.push(i);
		while (!Q.empty())
		{
			for (auto& j : Graph[Q.front()])
				if (fire[j.first] > min(fire[j.first], fire[Q.front()] + j.second))
				{
					fire[j.first] = min(fire[j.first], fire[Q.front()] + j.second);
					Q.push(j.first);
				}

			Q.pop();
		}
		for (auto& j : fire)
			maxxx = max(maxxx, j);
	}
	fout << maxxx;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}