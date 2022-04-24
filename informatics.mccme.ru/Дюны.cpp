#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	vector<vector<int>> wind(n, vector<int>(3));
	for (auto& i : wind)
		for (auto& j : i)
			fin >> j;

	for (auto& i : wind)
	{
		--i[0];
		--i[1];
	}

	vector<int> toCheck(m);
	for (auto& i : toCheck)
		fin >> i;
	for (auto& i : toCheck)
		--i;

	int res;
	for (auto& i : toCheck)
	{
		res = 0;
		for (auto& j : wind)
			if (j[0] <= i && i <= j[1])
			{
				if ((i - j[0]) % 2 == 0)
					res += j[2];
				else
					res -= j[2];
			}

		fout << res << '\n';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}