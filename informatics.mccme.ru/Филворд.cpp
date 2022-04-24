#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

string s;
vector<vector<char>> table(5, vector<char>(5));
vector<vector<int>> fire(5, vector<int>(5));

bool DFS(int a, int b, int depth)
{
	if (depth == s.size() - 1) 
		return true;
	fire[a][b] = 1;

	if (a > 0)
	{
		if ((fire[a - 1][b] == 0) && (table[a-1][b] == s[depth + 1])&&(DFS(a - 1, b, depth + 1)))
			return true;
	}
	if (a < 4)
	{
		if ((fire[a + 1][b] == 0) && (table[a + 1][b] == s[depth + 1]) && (DFS(a + 1, b, depth + 1)))
			return true;
	}
	if (b > 0)
	{
		if ((fire[a][b - 1] == 0) && (table[a][b - 1] == s[depth + 1]) && (DFS(a, b - 1, depth + 1)))
			return true;
	}
	if (b < 4)
	{
		if ((fire[a][b + 1] == 0)&&(table[a][b + 1] == s[depth + 1]) && (DFS(a, b + 1, depth + 1)))
			return true;
	}

	fire[a][b] = 0;
	return false;
}

int main()
{
	cin >> s;
	for (auto&i : table)
		for (auto&j : i)
			cin >> j;

	bool flag = false;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (table[i][j] == s[0])
				flag |= DFS(i, j, 0);

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}