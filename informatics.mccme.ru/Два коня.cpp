#include <fstream>
#include <vector>
#include <queue>
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

	int x1, y1, x2, y2;
	{
		char h1, h2;
		fin >> h1 >> y1 >> h2 >> y2; --y1; --y2;
		x1 = h1 - 'a'; x2 = h2 - 'a';
	}
	if ((x1 + y1 + x2 + y2) % 2 == 1)
	{
		fout << -1;
		fin.close();  //close input file
		fout.close(); //close output file

		return 0;

	}
	vector<vector<int>> fire(8, vector<int>(8, 1000000));
	queue<pair<int, int>> Q; Q.push({ x1, y1 }); fire[x1][y1] = 0;
	while (!Q.empty())
	{
		int x, y;
		x = Q.front().first + 2; y = Q.front().second + 1;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first + 2; y = Q.front().second - 1;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first - 2; y = Q.front().second + 1;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first - 2; y = Q.front().second - 1;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first + 1; y = Q.front().second - 2;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first - 1; y = Q.front().second - 2;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first + 1; y = Q.front().second + 2;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}
		x = Q.front().first - 1; y = Q.front().second + 2;
		if ((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7))
			if (fire[x][y] > fire[Q.front().first][Q.front().second] + 1)
			{
				fire[x][y] = fire[Q.front().first][Q.front().second] + 1;
				Q.push({ x, y });
			}

		Q.pop();
	}
	fout << fire[x2][y2] / 2;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}