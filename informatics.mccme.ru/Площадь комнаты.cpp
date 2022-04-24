#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int DFS(int x, int y, vector<vector<bool>>& used)
{
	int res{ 1 }; used[x][y] = true;
	if (!used[x - 1][y])
		res += DFS(x - 1, y, used);
	if (!used[x][y - 1])
		res += DFS(x, y - 1, used);
	if (!used[x + 1][y])
		res += DFS(x + 1, y, used);
	if (!used[x][y + 1])
		res += DFS(x, y + 1, used);

	return res;
}
int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<vector<bool>> used(n + 2, vector<bool>(n + 2, true));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char h; fin >> h;
			if (h == '.') used[i][j] = false;
		}
	}
	int x, y; fin >> x >> y;
	fout << DFS(x, y, used);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}