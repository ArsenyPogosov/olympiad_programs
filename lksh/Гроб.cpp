#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<int>> g;

bool win(int v)
{
	for (auto& i : g[v])
		if (!win(i))
			return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	g.resize(n);
	int root;
	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		if (p == 0)
			root = i;
		else
			g[p - 1].push_back(i);
	}
	if (win(root))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}