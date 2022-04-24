#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	int n = 6500;
	vector<bool> prime(n + 1, true);
	prime[0] = false;
	prime[1] = false;
	list<int> prime2;
	for (int i = 0; i <= n; ++i)
		if (prime[i])
		{
			prime2.push_back(i);
			for (int j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	list<pair<int, int>> ans;
	for (auto&i : prime2)
	{
		int pcount = 0;
		int tek = n;
		while (tek > 1)
		{
			tek /= i;
			pcount += tek;
		}
		ans.push_back({ i, pcount });
	}
	
	for (auto&i : ans)
		cout << i.first << '^' << i.second << 'x';
	system("PAUSE");
}