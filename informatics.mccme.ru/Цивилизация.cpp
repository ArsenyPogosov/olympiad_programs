#include <fstream>
#include <vector>
#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m, x1, y1, x2, y2;
	fin >> n >> m >> x1 >> y1 >> x2 >> y2;
	vector<vector<char>> map(n + 2, vector<char>(m + 2, '#'));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> map[i][j];
	vector<vector<int>> fire(n + 2, vector<int>(m + 2, 1000000000)); 
	fire[x1][y1] = 0;
	vector<vector<char>> FromWho(n + 2, vector<char>(m + 2, '&'));
	queue<pair<int, int>> Q; Q.push({ x1, y1 });
	while (!Q.empty())
	{
		if (map[Q.front().first - 1][Q.front().second] != '#')
			if (fire[Q.front().first - 1][Q.front().second] >
				fire[Q.front().first][Q.front().second] + 1 + (map[Q.front().first - 1][Q.front().second] == 'W'))
			{
				fire[Q.front().first - 1][Q.front().second] =
					fire[Q.front().first][Q.front().second] + 1 +
					(map[Q.front().first - 1][Q.front().second] == 'W');
				FromWho[Q.front().first - 1][Q.front().second] = 'N';
				Q.push({ Q.front().first - 1, Q.front().second });
			}
		if (map[Q.front().first + 1][Q.front().second] != '#')
			if (fire[Q.front().first + 1][Q.front().second] >
				fire[Q.front().first][Q.front().second] + 1 + (map[Q.front().first + 1][Q.front().second] == 'W'))
			{
				fire[Q.front().first + 1][Q.front().second] =
					fire[Q.front().first][Q.front().second] + 1 +
					(map[Q.front().first + 1][Q.front().second] == 'W');
				FromWho[Q.front().first + 1][Q.front().second] = 'S';
				Q.push({ Q.front().first + 1, Q.front().second });
			}
		if (map[Q.front().first][Q.front().second + 1] != '#')
			if (fire[Q.front().first ][Q.front().second+ 1] >
				fire[Q.front().first][Q.front().second] + 1 + (map[Q.front().first][Q.front().second + 1] == 'W'))
			{
				fire[Q.front().first][Q.front().second + 1] =
					fire[Q.front().first][Q.front().second] + 1 +
					(map[Q.front().first][Q.front().second + 1] == 'W');
				FromWho[Q.front().first][Q.front().second + 1] = 'E';
				Q.push({ Q.front().first, Q.front().second + 1 });
			}
		if (map[Q.front().first][Q.front().second - 1] != '#')
			if (fire[Q.front().first][Q.front().second - 1] >
				fire[Q.front().first][Q.front().second] + 1 + (map[Q.front().first][Q.front().second - 1] == 'W'))
			{
				fire[Q.front().first][Q.front().second - 1] =
					fire[Q.front().first][Q.front().second] + 1 +
					(map[Q.front().first][Q.front().second - 1] == 'W');
				FromWho[Q.front().first][Q.front().second - 1] = 'W';
				Q.push({ Q.front().first, Q.front().second - 1 });
			}

		Q.pop();
	}
	if (fire[x2][y2] == 1000000000)
	{
		fout << -1;

		fin.close();  //close input file
		fout.close(); //close output file

		return 0;
	}
	fout << fire[x2][y2] << '\n';
	string res{ "" };
	pair<int, int> it{ x2, y2 };
	while (FromWho[it.first][it.second] != '&')
	{
		res = FromWho[it.first][it.second] + res;
		if (FromWho[it.first][it.second] == 'N') ++it.first;
		else
		if (FromWho[it.first][it.second] == 'E') --it.second;
		else
		if (FromWho[it.first][it.second] == 'S') --it.first;
		else
		if (FromWho[it.first][it.second] == 'W') ++it.second;
	}
	fout << res;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}