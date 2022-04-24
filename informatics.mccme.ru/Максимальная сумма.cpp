#include <fstream>
#include <vector>
#include <deque>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<int>> linePartialSum, columnPartialSum;

int FrameSum(int x1, int y1, int x2, int y2)
{
	int l1, l2, l3, l4;
	l1 = linePartialSum[y1][x2] - linePartialSum[y1][x1];
	l2 = columnPartialSum[y2][x2] - columnPartialSum[y1][x2];
	if (x1 > 0)
		l3 = linePartialSum[y2][x2 - 1] - linePartialSum[y2][x1 - 1];
	else
		l3 = linePartialSum[y2][x2 - 1];
	if (y1 > 0)
		l4 = columnPartialSum[y2 - 1][x1] - columnPartialSum[y1][x1];
	else
		l4 = columnPartialSum[y2 - 1][x1];

	return l1 + l2 + l3 + l4;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int m, n;
	vector<vector<int>> table(m, vector<int>(n));
	linePartialSum = columnPartialSum = table;
	for (auto&i : table)
		for (auto&j : i)
			fin >> j;
	for (int i = 0; i <= n - 1; ++i)
	{
		linePartialSum[i][0] = table[i][0];
		for (int j = 1; j <= m - 1; ++j)
			linePartialSum[i][j] = linePartialSum[i][j - 1] + table[i][j];
	}

	for (int j = 0; j <= m - 1; ++j)
	{
		linePartialSum[0][j] = table[0][j];
		for (int i = 1; i <= m - 1; ++i)
			linePartialSum[i][j] = linePartialSum[i - 1][j] + table[i][j];
	}

	deque<int> rightSight;
	pair<int, int> maxLT = { 0, 0 }, maxRB = { 1, 1 };
	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= m - 1; ++j)
		{

		}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}