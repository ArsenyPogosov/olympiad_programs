#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n; long long N = 1;
	while (N < n) N *= 2;
	vector<vector<long long>> res;
	long long a = N / 2;
	while (a > 0)
	{
		vector<vector<long long>> ask(2, vector<long long>());
		for (long long i = 0; i < n; ++i)
			ask[(i / a) % 2].push_back(i);
		long long a1, a2;
		if (ask[0].size() > 0)
		{
			cout << "? " << ask[0].size() << ' ';
			for (auto& i : ask[0]) cout << i + 1 << ' ';
			cout << endl;
			cin >> a1;
		}
		else
			a1 = 0;

		if (ask[1].size() > 0)
		{
			cout << "? " << ask[1].size() << ' ';
			for (auto& i : ask[1]) cout << i + 1 << ' ';
			cout << endl;
			cin >> a2;
		}
		else
			a2 = 0;
		res.push_back({ a1, a2 });
		a /= 2;
	}
	cout << "! ";
	for (long long i = 0; i < n; ++i)
	{
		a = N / 2;
		long long c = 0;
		long long ress = 0;
		while (a > 0)
		{
			ress |= res[c][1 - ((i / a) % 2)];
			a /= 2;
			++c;
		}
		cout << ress << ' ';
	}
	cout << endl;

	return 0;
}