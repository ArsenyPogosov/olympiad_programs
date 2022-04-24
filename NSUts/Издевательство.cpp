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

	int N;
	fin >> N;
	vector<vector<int>> map(N, vector<int>(N));

	for (auto& i : map)
		for (auto& j : i) fin >> j;

	int min = 100000000;
	for (int i = 0; i <= N - 1; ++i)
		for (int j = 0; j <= N - 1; ++j)
			for (int k = 0; k <= N - 1; ++k)
				if ((i != j) && (j != k) && (k != i))
					if (map[i][j] + map[j][k] + map[k][i] < min)
						min = map[i][j] + map[j][k] + map[k][i];

	fout << min;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}