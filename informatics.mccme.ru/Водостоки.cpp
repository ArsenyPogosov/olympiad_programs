#include <fstream>
#include <vector>
#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> REmap;

void DFS(int i, int j, int k)
{
	REmap[i][j] = k;
	if ((map[i + 1][j] == map[i][j]) && (REmap[i + 1][j] != -1) && (REmap[i + 1][j] != k))
		DFS(i + 1, j, k);
	if ((map[i][j + 1] == map[i][j]) && (REmap[i][j + 1] != -1) && (REmap[i][j + 1] != k))
		DFS(i, j + 1, k);
	if ((map[i - 1][j] == map[i][j]) && (REmap[i - 1][j] != -1) && (REmap[i - 1][j] != k))
		DFS(i - 1, j, k);
	if ((map[i][j - 1] == map[i][j]) && (REmap[i][j - 1] != -1) && (REmap[i][j - 1] != k))
		DFS(i, j - 1, k);
}

bool CheckDFS(int i, int j, int k, pair<int, int> father)
{
	if ((map[i + 1][j] == map[i][j]) && (REmap[i + 1][j] == -1))
		return false;
	if ((map[i][j + 1] == map[i][j]) && (REmap[i][j + 1] == -1))
		return false;
	if ((map[i - 1][j] == map[i][j]) && (REmap[i - 1][j] == -1))
		return false;
	if ((map[i][j - 1] == map[i][j]) && (REmap[i][j - 1] == -1))
		return false;

	if ((map[i + 1][j] == map[i][j]) && (REmap[i + 1][j] == k) && (pair<int, int>{ i + 1, j} != father))
		if (!CheckDFS(i + 1, j, k, { i, j }))
			return false;
	if ((map[i][j + 1] == map[i][j]) && (REmap[i][j + 1] == k) && (pair<int, int>{ i, j + 1} != father))
		if (!CheckDFS(i, j + 1, k, { i, j }))
			return false;
	if ((map[i - 1][j] == map[i][j]) && (REmap[i - 1][j] == k) && (pair<int, int>{ i - 1, j} != father))
		if (!CheckDFS(i - 1, j, k, { i, j }))
			return false;
	if ((map[i][j - 1] == map[i][j]) && (REmap[i][j - 1] == k) && (pair<int, int>{ i, j - 1} != father))
		if (!CheckDFS(i, j - 1, k, { i, j }))
			return false;

	return true;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	map = vector<vector<int>>(n + 2, vector<int>(m + 2, 10001));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			fin >> map[i][j];
	REmap = vector<vector<int>>(n + 2, vector<int>(m + 2, -1));
	int count{ 0 };
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!((map[i - 1][j] < map[i][j]) || (map[i + 1][j] < map[i][j]) || (map[i][j - 1] < map[i][j]) || (map[i][j + 1] < map[i][j])))
				REmap[i][j] = count++;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if ((map[i + 1][j] == map[i][j]) && (REmap[i + 1][j] != -1) && (REmap[i + 1][j] != REmap[i][j]))
				DFS(i + 1, j, REmap[i][j]);
			if ((map[i][j + 1] == map[i][j]) && (REmap[i][j + 1] != -1) && (REmap[i][j + 1] != REmap[i][j]))
				DFS(i, j + 1, REmap[i][j]);
			if ((map[i - 1][j] == map[i][j]) && (REmap[i - 1][j] != -1) && (REmap[i - 1][j] != REmap[i][j]))
				DFS(i - 1, j, REmap[i][j]);
			if ((map[i][j - 1] == map[i][j]) && (REmap[i][j - 1] != -1) && (REmap[i][j - 1] != REmap[i][j]))
				DFS(i, j - 1, REmap[i][j]);
		}
	vector<int> Checked(n*m, false);
	vector<int> Res(n*m, false);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (REmap[i][j] != -1)
				if (!Checked[REmap[i][j]])
				{
					Res[REmap[i][j]] = CheckDFS(i, j, REmap[i][j], { -1, -1 });
					Checked[REmap[i][j]] = true;
				}

	count = 0;
	for (auto&i : Res)
		if (i)
			++count;
	fout << count;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}