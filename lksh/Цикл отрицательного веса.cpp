#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 1000000000;
const int NO_PATH = 100000;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (auto& i : g)
		for (auto& j : i)
			cin >> j;
	vector<int> dist(n, INF), p(n, -1);


	return 0;
}