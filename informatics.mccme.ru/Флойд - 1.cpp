#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<vector<int>> MatSm(n, vector<int>(n));
	for (auto& i : MatSm)
		for (auto& j : i)
			fin >> j;

	vector<vector<long long>> Put(n, vector<long long>(n, 1000000000)), HelpPut(n, vector<long long>(n));
	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= n - 1; ++j)
			Put[i][j] = MatSm[i][j];

	for (int glub = 0; glub <= n - 1; ++glub, Put = HelpPut)
		for (int i = 0; i <= n - 1; ++i)
			for (int j = 0; j <= n - 1; ++j)
				HelpPut[i][j] = min(Put[i][j], Put[i][glub] + Put[glub][j]);

	for (auto& i : Put)
	{
		for (auto& j : i)
			fout << j << ' ';
		fout << '\n';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}