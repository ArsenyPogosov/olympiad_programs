//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n, m, k; cin >> n >> m >> k;
	if (k > 4 * n * m - 2 * n - 2 * m)
	{
		cout << "NO\n";
		return 0;
	}
	else
		cout << "YES\n";

	int c = 0, s = 0, d;
	string res = "";
	if (min(m - 1, k) > 0)
	{
		c += min(m - 1, k);
		++s;
		res += to_string(c) + " R\n";
	}
	if (k == c)
	{
		cout << s << '\n' << res;
		return 0;
	}
	if (min(m - 1, k - c) > 0)
	{
		res += to_string(min(m - 1, k - c)) + " L\n";
		c += min(m - 1, k - c);
		++s;
	}
	if (k == c)
	{
		cout << s << '\n' << res;
		return 0;
	}
	for (int i = 1; i < n; ++i)
	{
		++c; ++s; res += "1 D\n";
		if (k == c)
		{
			cout << s << '\n' << res;
			return 0;
		}
		d = k - c;
		if (d < m * 3 - 3)
		{
			if (d / 3 > 0)
			{
				c += d - (d % 3); ++s; res += to_string(d / 3) + " RUD\n";
			}
			if (d % 3 >= 1)
			{
				++c; ++s; res += "1 R\n";
			}
			if (d % 3 >= 2)
			{
				++c; ++s; res += "1 U\n";
			}
		}
		else
		{
			if (m - 1 > 0)
			{
				c += 3 * m - 3; ++s; res += to_string(m - 1) + " RUD\n";
			}
		}
		if (k == c)
		{
			cout << s << '\n' << res;
			return 0;
		}
		d = k - c; 
		if (d < m - 1)
		{
			c += d; ++s; res += to_string(d) + " L\n";
		}
		else
		{
			if (m - 1 > 0)
			{
				c += m - 1; ++s; res += to_string(m - 1) + " L\n";
			}
		}
		if (k == c)
		{
			cout << s << '\n' << res;
			return 0;
		}
	}
	if (k == c)
	{
		cout << s << '\n' << res;
		return 0;
	}
	++s; res += to_string(k - c) + " U\n";
	cout << s << '\n' << res;

	return 0;
}