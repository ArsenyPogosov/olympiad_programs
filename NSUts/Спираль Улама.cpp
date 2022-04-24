#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, mdiv;

void erat(int n)
{
	prime.reserve(int(n / max(1.0, log(n))) + 10); // lol
	mdiv.resize(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		if (!mdiv[i])
		{
			mdiv[i] = i;
			prime.push_back(i);
		}
		for (auto& p : prime)
		{
			if (i * p > n || p > mdiv[i]) break;
			mdiv[i * p] = p;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	erat(n * n + 1);
	vector<vector<char>> res(n, vector<char>(n)); 
	int x = n / 2, y = x, num = 1; res[x][y] = '.';
	for (int len = 2; len < n; len += 2)
	{
		++y; ++num; res[x][y] = (mdiv[num] == num ? '*' : '.');
		for (int i = 0; i < len - 1; ++i)
		{
			--x; ++num; res[x][y] = (mdiv[num] == num ? '*' : '.');
		}
		for (int i = 0; i < len; ++i)
		{
			--y; ++num; res[x][y] = (mdiv[num] == num ? '*' : '.');
		}
		for (int i = 0; i < len; ++i)
		{
			++x; ++num; res[x][y] = (mdiv[num] == num ? '*' : '.');
		}
		for (int i = 0; i < len; ++i)
		{
			++y; ++num; res[x][y] = (mdiv[num] == num ? '*' : '.');
		}
	}
	for (auto& i : res)
	{
		for (auto& j : i)
			cout << j;
		cout << '\n';
	}

	return 0;
}