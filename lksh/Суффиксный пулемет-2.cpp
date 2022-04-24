#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const long long bb = 107, p = 1000000007;

int main()
{
	long long k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	long long an = a.size(), bn = b.size();
	long long ah, bh, bbb, ai, bi, l;
	list<long long> res;
	list<vector<long long>> stop;
	vector<vector<int>> check(an + 1, vector<int>(bn + 1));
	stop.push_back({ an, -1, 0 });
	while (true)
	{
		res.clear();
		ai = stop.front()[0];
		bi = stop.front()[1];
		l = stop.front()[2];
		if (check[ai][bi])
			continue;
		check[ai][bi] = true;
		bbb = 1;
		ah = 0;
		bh = 0;
		stop.pop_front();
		while (true)
		{
			--ai;
			++bi;
			if (bi >= bn)
				break;
			if (ai < 0)
			{
				l = 228;
				break;
			}
			++l;
			ah = (ah + ((a[ai] - 'a' + 1) * bbb) % p) % p;
			bh = ((bh * bb) % p + (b[bi] - 'a' + 1)) % p;
			bbb = (bbb * bb) % p;
			if (ah == bh && l >= k)
			{
				res.push_back(l);
				stop.push_back({ ai, bi, l });
				l = bh = ah = 0;
				bbb = 1;
			}
		}
		if (l == 0)
		{
			cout << res.size() << '\n';
			for (auto& i : res)
				cout << i << ' ';
			return 0;
		}
		if (stop.empty())
		{
			cout << 0;
			return 0;
		}
	}

	return 0;
}