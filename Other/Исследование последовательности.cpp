#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string next(string tek)
{
	string res = "";
	int c = 1, i = 1;
	char t = tek[0];
	while (i < tek.size())
	{
		if (tek[i] == t) ++c;
		else
		{
			res += to_string(c) + t;
			t = tek[i];
			c = 1;
		}
		++i;
	}
	res += to_string(c) + t;
	res = res.substr(max(0, int(res.size() - 1000)), 1000);
	return res;
}

int main()
{
	vector<string> h(34);
	long long n, m; cin >> n >> m; --n;
	h[0] = "1";
	for (int i = 1; i < 34; ++i)
		h[i] = next(h[i - 1]);

	string r;
	if (n < 30) 
		r = h[n];
	else
	{
		n -= 30; n %= 4;
		r = h[n + 30];
	}
	cout << r.substr(max(0, int(r.size() - m)), m) << '\n';

	return 0;
}