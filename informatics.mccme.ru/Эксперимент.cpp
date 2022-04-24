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

	int n, m, k, l, s;
	fin >> n >> m >> k >> l >> s;
	vector<vector<long long>> Map(n, vector<long long>(m));
	for (auto&i : Map)
		for (auto&j : i)
			fin >> j;
	vector<vector<long long>> PartialSum(n + 1, vector<long long>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			PartialSum[i][j] = PartialSum[i - 1][j] + PartialSum[i][j - 1] - PartialSum[i - 1][j - 1] + Map[i - 1][j - 1];
	long long count{ 0 };
	for (int i = 1; i <= n - k + 1; ++i)
		for (int j = 1; j <= m - l + 1; ++j) {
			if (PartialSum[i + k - 1][j + l - 1] - PartialSum[i - 1][j + l - 1] - PartialSum[i + k - 1][j - 1] + PartialSum[i - 1][j - 1] == s)
				++count;
		}
	fout << count;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}