#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct shortrangemegaset
{
	deque<pair<int64_t, int64_t>> data;

	void push_back(int64_t x, int64_t i)
	{
		while (data.size() && data.back().first <= x)
			data.pop_back();
		data.emplace_back(x, i);
	}

	void pop_front(int64_t i)
	{
		if (data.front().second == i)
			data.pop_front();
	}

	int64_t front()
	{
		return data.front().first;
	}

	size_t size()
	{
		return data.size();
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int64_t n, k, x;
	cin >> n >> k >> x;
	vector<shortrangemegaset> sortres(x + 1);
	sortres[0].push_back(0, 0);
	for (int64_t i = 1; i <= x; ++i)
		sortres[i].push_back(-1, 0);
	for (int64_t j = 0; j < n; ++j)
	{
		int64_t a; cin >> a;
		sortres[0].push_back(-1, j + 1);
		for (int64_t i = x; i > 0; --i)
			sortres[i].push_back((sortres[i - 1].size() && sortres[i - 1].front() > -1 ? sortres[i - 1].front() + a : -1), j + 1);
		if (j - k + 1 >= 0)
		{
			for (int64_t i = 0; i <= x; ++i)
				sortres[i].pop_front(j - k + 1);
		}
	}
	cout << sortres[x].front() << '\n';

	return 0;
}