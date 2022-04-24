#include <iostream>
#include <vector>
#include <stack>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int graph[1000001];
int fire[1000001];

stack<int> vert;

long long p = 1000000007;

pair<bool, pair<int, int>> DFS(int v, int parent)
{
	fire[v] = 1;
	vert.push(v);
	pair<bool, pair<int, int>> ans{ false, { 1, 0 } };

	int i = graph[v];
	if ((i != parent) && (i != v))
	{
		if (fire[i] == 2)
		{
			ans.first = true;
		}
		if (fire[i] == 0)
		{
			auto res = DFS(i, v);
			ans.first |= res.first;
			ans.second.first += res.second.first;
			ans.second.second += res.second.second;
		}
		if (fire[i] == 1)
		{
			int count = 1;
			while (!vert.empty())
			{
				if ((vert.top() == i)) break;
				if (!vert.empty())
					vert.pop();
				++count;
			}
			ans.second.second = count;
		}
	}

	if (!vert.empty())
		vert.pop();
	fire[v] = 2;
	return ans;
}

long long power(long long k, int a)
{
	if (a == 0)
		return 1;

	if (a % 2 == 1)
		return (power(k, a - 1)*(k - 1)) % p;

	long long res = power(k, a / 2);
	return (res * res) % p;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h; --h;
		graph[i] = h;
	}

	long long ans = 1;

	for (int i = 0; i < n; ++i)
	{
		if (fire[i] == 0)
		{
			pair<bool, pair<int, int>> ret{ false,{ 0, 0 } };
			int v = i, parent = -1;
			while (true)
			{
				fire[v] = 1;
				vert.push(v);
				++ret.second.first;

				int u = graph[v];
				if ((u == parent) || (u == v))
				{
					while (!vert.empty())
					{
						fire[vert.top()] = 2;
						vert.pop();
					}
					break;
				}
				if (fire[u] == 2)
				{
					ret.first = true;
					while (!vert.empty())
					{
						fire[vert.top()] = 2;
						vert.pop();
					}
					break;
				}
				if (fire[u] == 0)
				{
					parent = v;
					v = u;
					continue;
				}
				if (fire[u] == 1)
				{
					int count = 1;
					while (!vert.empty())
					{
						fire[vert.top()] = 2;
						if ((vert.top() == u)) ret.second.second = count;
						if (!vert.empty())
							vert.pop();
						++count;
					}
					break;					
				}
			}

			if (!ret.first)
			{
				if (ret.second.second == 0)
				{
					ans = (ans * k) % p;
					ans = (ans * power(k, ret.second.first - 1)) % p;
				}
				else
				{
					long long mult;
					if (ret.second.second % 2 == 0)
					{
						mult = (power(k, ret.second.second) + k - 1 + p) % p;
					}
					else
					{
						mult = (power(k, ret.second.second) - k + 1 + p) % p;
					}
					mult = (mult * power(k, ret.second.first - ret.second.second)) % p;
					ans = (ans * mult) % p;
				}
			}
			else
			{
				ans = (ans * power(k, ret.second.first)) % p;
			}
		}
	}
	cout << ans;

	return 0;
}