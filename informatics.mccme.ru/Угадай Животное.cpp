#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<string, vector<string>>> animals(n);
	for (auto&i : animals)
	{
		cin >> i.first;
		int h; cin >> h;
		i.second.resize(h);
		for (auto&j : i.second)
			cin >> j;
		sort(i.second.begin(), i.second.end());
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			int it1 = 0, it2 = 0, tekAns = 1;
			auto& a = animals[i].second, b = animals[j].second;
			while ((it1 < a.size()) && (it2 < b.size()))
			{
				if (a[it1] > b[it2])
				{
					++it2;
					continue;
				}
				if (a[it1] < b[it2])
				{
					++it1;
					continue;
				}
				++tekAns;
				++it1;
				++it2;
			}
			ans = max(ans, tekAns);
		}
	cout << ans;

	return 0;
}