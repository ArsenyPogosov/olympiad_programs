#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string task = "BSUIROPENX";

int main()
{
	int n; cin >> n;
	vector<long long> countl(11), countr(11);
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s.size() < 1 || s.size() > 9) continue;
		if (task.substr(0, s.size()) == s)
			++countl[s.size()];
		if (task.substr(10 - s.size(), s.size()) == s)
			++countr[s.size()];
	}
	long long res = 0;
	for (int i = 1; i < 10; ++i)
		res += countl[i] * countr[10 - i];
	cout << res;

	return 0;
}