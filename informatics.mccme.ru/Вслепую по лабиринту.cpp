#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

vector<vector<bool>> used(100, vector<bool>(100, false));

void dfs(int x, int y)
{
	used[x][y] = true;
	string answ;
	if (used[x - 1][y] == false)
	{
		cout << "WEST\n";
		cin >> answ;
		if (answ == "BLOCKED") used[x - 1][y] = true;
		else { dfs(x - 1, y); cout << "EAST\n"; cin >> answ; }
	}
	if (used[x + 1][y] == false)
	{
		cout << "EAST\n";
		cin >> answ;
		if (answ == "BLOCKED") used[x + 1][y] = true;
		else { dfs(x + 1, y); cout << "WEST\n"; cin >> answ; }
	}
	if (used[x][y - 1] == false)
	{
		cout << "SOUTH\n";
		cin >> answ;
		if (answ == "BLOCKED") used[x][y - 1] = true;
		else { dfs(x, y - 1); cout << "NORTH\n"; cin >> answ;}
	}
	if (used[x][y + 1] == false)
	{
		cout << "NORTH\n";
		cin >> answ;
		if (answ == "BLOCKED") used[x][y + 1] = true;
		else { dfs(x, y + 1); cout << "SOUTH\n"; cin >> answ; }
	}
}

int main()
{
	dfs(50, 50);
	cout << "DONE";

	return 0;
}