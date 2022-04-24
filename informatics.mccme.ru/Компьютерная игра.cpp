#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	vector<int> levels(p+1);
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;
		++levels[h];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		char com;
		int h;
		cin >> com >> h;
		if (com == '?')
			cout << levels[h] << '\n';
		if (com == '+')
		{
			if (h != p) levels[h + 1] += levels[h];
			levels[h] = 0;
		}
	}

	return 0;
}