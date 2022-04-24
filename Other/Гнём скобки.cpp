#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n; n <<= 1;
	string s; cin >> s;

	stack<char> res;
	for (auto& i : s)
	{
		if (res.size() && abs(res.top() - i) <= 2)
			res.pop();
		else
			res.push(i);
	}

	cout << res.size() / 2 << '\n';

	return 0;
}