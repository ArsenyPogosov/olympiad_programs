#include <bits/stdc++.h>
using namespace std;

vector<int> c(10);

string gen(int l)
{
	string res = "";
	for (int i = (l > 1); i < 10; ++i)
		if (c[i])
		{
			--c[i];
			res += char('0' + i);
			break;
		}
	--l;
	int t = 0;
	while (l > 0)
	{
		if (c[t])
		{
			--c[t];
			res += char('0' + t);
			--l;
		}
		else
			++t;
	}

	return res;
}

int main()
{
	string s; cin >> s;
	int n = s.size();
	for (auto& i : s) ++c[i - '0'];
	if (n == 1)
	{
		cout << "-1 -1\n";
		return 0;
	}
	if (n > 2 * 19)
	{
		cout << "-1 -1\n";
		return 0;
	}
	if (n == 2 * 19)
	{
		if (c[1] == 2 && c[0] == 18 * 2)
			cout << "1000000000000000000 1000000000000000000\n";
		else
			cout << "-1 -1\n";
		return 0;
	}
	if (n == 2 * 19 - 1)
	{
		if (c[1] < 1 || c[0] < 18)
		{
			cout << "-1 -1\n";
			return 0;
		}
	}
	if (n == 2)
	{
		cout << min(s[0], s[1]) << ' ' << max(s[0], s[1]) << '\n';
		return 0;
	}
	if (n - c[0] == 0)
	{
		cout << "-1 -1\n";
		return 0;
	}
	int can19 = (c[1] >= 1 && c[0] >= 18);
	int opt = max(1, n - 18 - can19);
	if (n - c[0] == 1 && opt > 1)
	{
		cout << "-1 -1\n";
		return 0;
	}
	string a, b;
	if (n - opt == 19)
	{
		c[1] -= 1;
		c[0] -= 18;
	}
	a = gen(opt);
	if (n - opt == 19)
	{
		c[1] += 1;
		c[0] += 18;
	}
	b = gen(n - opt);
	cout << a << ' ' << b << '\n';

	return 0;
}