#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<int>> Graph;
vector<int> fire;

bool DFS(int x, int ig)
{
	fire[x] = 1;
	for (auto&i : Graph[x])
		if (i != ig)
		{
			if (fire[i] == 1)
				return true;
			if (fire[i] == 0)
				if (DFS(i, x))
					return true;
		}

	fire[x] = 2;
	return false;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	double count{ 0 };
	fin >> n;
	Graph = vector<list<int>>(n);
	int h;
	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= n - 1; ++j)
		{
			fin >> h;
			if (h == 1)
			{
				Graph[i].push_back(j);
				++count;
			}
		}
	count /= 2;
	if (count != n-1)
	{
		fout << "NO";

		fin.close();  //close input file
		fout.close(); //close output file
		return 0;
	}

	fire = vector<int>(n, 0);
	for (int i = 0; i <= n - 1; ++i)
		if (fire[i] == 0)
			if (DFS(i, -1))
			{
				fout << "NO";

				fin.close();  //close input file
				fout.close(); //close output file
				return 0;
			}

	fout << "YES";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}