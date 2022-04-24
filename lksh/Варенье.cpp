#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<long long> afterBlock(n), res(n, -1);
	for (auto&i : afterBlock)
		cin >> i;
	for (auto&i : afterBlock)
	{
		long long h;
		cin >> h;
		i -= h;
	}
	for (int i = 0; i < n; ++i)
		if (afterBlock[i] >= 0)
			res[i] = 0;
	long long m;
	cin >> m;
	vector<vector<long long>> changes(m, vector<long long>(4));
	for (auto&i : changes)
	{
		cin >> i[0] >> i[1] >> i[2] >> i[3];
		--i[0];
		--i[1];
	}
	long long mk = sqrt(m);
	for (long long i = 0; i < m; i += mk)
	{
		vector<pair<long long, long long>> scops(n + 1);
		for (long long j = i; j < min(i + mk, m); ++j)
		{
			auto change = changes[j];
			scops[change[0]].first += change[2];
			scops[change[0]].second += change[3];
			scops[change[1] + 1].first -= change[2] + change[3] * (change[1] - change[0] + 1);
			scops[change[1] + 1].second -= change[3];
		}
		long long toAdd = 0, d = 0; // d <=> toAddtotoAdd
		for (long long j = 0; j < n; ++j)
		{
			toAdd += scops[j].first;
			d += scops[j].second;
			afterBlock[j] = afterBlock[j] + toAdd;
			if ((afterBlock[j] >= 0) && (res[j] == -1))
			{
				long long in = afterBlock[j] - toAdd;
				long long ress = i;
				while (in < 0)
				{
					auto change = changes[ress++];
					if (change[0] <= j && j <= change[1])
						in += change[2] + change[3] * (j - change[0]);
				}
				res[j] = ress;				
			}
			toAdd += d;
		}
	}
	for (auto&i : res)
		cout << i << ' ';

	return 0;
}