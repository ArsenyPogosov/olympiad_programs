#include <fstream>
#include <vector>
#include <queue>
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

	int n, m;
	fin >> n >> m;
	vector<vector<char>> Map(n + 2, vector<char>(m + 2, '*'));
	vector<vector<int>> Fire(n + 2, vector<int>(m + 2, 1000000000));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> Map[i][j];
	queue<pair<int, int>> Q;
	Q.push({ 1, 1 });
	Fire[1][1] = 0;
	while (!Q.empty())
	{
		for (int i = Q.front().first; true; --i)
			if (Map[i][Q.front().second] == '*')
			{
				if (Fire[i + 1][Q.front().second] > Fire[Q.front().first][Q.front().second] + 1)
				{
					Fire[i + 1][Q.front().second] = Fire[Q.front().first][Q.front().second] + 1;
					Q.push({ i + 1, Q.front().second });
				}
				break;
			}
		for (int i = Q.front().first; true; ++i)
			if (Map[i][Q.front().second] == '*')
			{
				if (Fire[i - 1][Q.front().second] > Fire[Q.front().first][Q.front().second] + 1)
				{
					Fire[i - 1][Q.front().second] = Fire[Q.front().first][Q.front().second] + 1;
					Q.push({ i - 1, Q.front().second });
				}
				break;
			}
		for (int j = Q.front().second; true; --j)
			if (Map[Q.front().first][j] == '*')
			{
				if (Fire[Q.front().first][j + 1] > Fire[Q.front().first][Q.front().second] + 1)
				{
					Fire[Q.front().first][j + 1] = Fire[Q.front().first][Q.front().second] + 1;
					Q.push({ Q.front().first, j + 1 });
				}
				break;
			}
		for (int j = Q.front().second; true; ++j)
			if (Map[Q.front().first][j] == '*')
			{
				if (Fire[Q.front().first][j - 1] > Fire[Q.front().first][Q.front().second] + 1)
				{
					Fire[Q.front().first][j - 1] = Fire[Q.front().first][Q.front().second] + 1;
					Q.push({ Q.front().first, j - 1 });
				}
				break;
			}

		Q.pop();
	}
	if (Fire[n][m] == 1000000000) fout << -1;
	else fout << Fire[n][m];

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}