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

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto&i : a)
	{
		cin >> i;
		i %= m;
	}
	vector<bool> product(m), product2;
	for (auto&i: a)
	{
		product2 = product;
		for (int j = 0; j < m; ++j)
			if (product[j])
				product2[(i * j) % m] = true;
		product = product2;
		product[i] = true;
	}
	for (int i = m - 1; i >= 0; --i)
		if (product[i])
		{
			cout << i; 
			break;
		}

	return 0;
}