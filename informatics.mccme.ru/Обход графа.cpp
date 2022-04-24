#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, a;
	fin >> n >> a;
	--a;
	vector<list<int>> Graph(n);
	int h;
	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= n - 1; ++j)
		{
			fin >> h;
			if (h == 1)
				Graph[i].push_back(j);
		}

	vector<bool> fire(n, false);
	fire[a] = true;
	int count{ 1 };
	queue<int> Q;
	Q.push(a);
	while (!Q.empty())
	{
		for (auto i: Graph[Q.front()])
			if (!fire[i])
			{
				fire[i] = true;
				Q.push(i);
				++count;
			}

		Q.pop();
	}

	fout << count;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}