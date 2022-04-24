#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int n = 3;

vector<pair<int, int>> step(int x, int y)
{
	vector<pair<int, int>> res, s{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	for (auto& i : s)
	{
		int nx = x + i.first, ny = y + i.second;
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
			res.push_back({ nx, ny });
	}
	return res;
}

vector<pair<int, int>> step(pair<int, int> xy)
{
	return step(xy.first, xy.second);
}

int line(int x, int y)
{
	return x * n + y;
}

int line(pair<int, int> xy)
{
	return line(xy.first, xy.second);
}

pair<int, int> table(int x)
{
	return { x / n, x % n };
}

vector<vector<int>> nxt(vector<int> now)
{
	vector<vector<int>> res;
	for (int i = 0; i < n * n; ++i)
		for (auto& s : step(table(i)))
		{
			int j = line(s);
			res.push_back(now);
			swap((*prev(res.end()))[i], (*prev(res.end()))[j]);
		}
	return res;
}

int good(vector<int> now)
{
	int res = 0;
	for (int i = 0; i < 9; ++i)
	{
		auto a = table(i), b = table(now[i] - 1);
		res += abs(a.first - b.first) + abs(a.second - b.second);
	}
	return -res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> start(n * n), stop(n * n); iota(stop.begin(), stop.end(), 1);
	for (auto& i : start) cin >> i;
	map<vector<int>, int> d; d[start] = 0;
	priority_queue<pair<int, vector<int>>> Q; Q.push({ 0, start });
	int aaa = 1e9;
	while (Q.size())
	{
		vector<int> now = Q.top().second;  
		int dnow = d[now], ost = -Q.top().first;
		Q.pop();
		if (dnow * 2 + ost >= aaa * 2) continue;
		if (now == stop)
		{
			aaa = dnow;
			continue;
		}
		for (auto& i : nxt(now))
		{
			auto it = d.emplace(i, 1e9).first;
			if (it->second > dnow + 1)
			{
				it->second = dnow + 1;
				Q.push({ good(i), i });
			}
		}
	}
	cout << d[stop] << '\n';

	return 0;
}