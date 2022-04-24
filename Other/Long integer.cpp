#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = 1e9 + 7;
vector<long long> res;

int main()
{
	string s; cin >> s; int n; cin >> n;
	res.reserve(2 * 1e5);
	res.push_back(0);
	for (auto& i : s)
		res.push_back((res[res.size()-1] * 10 + (i - '0')) % p);
	for (int i = 0; i < n; ++i)
	{
		char h; cin >> h;
		if (h == '+')
		{
			char d; cin >> d;
			s += d;
			res.push_back((res[res.size() - 1] * 10 + (d - '0')) % p);
		}
		if (h == '-')
		{
			res.pop_back();
		}
		cout << res[res.size() - 1] << '\n';
	}

	return 0;
}