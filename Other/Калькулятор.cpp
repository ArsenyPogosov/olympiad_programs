#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const __int128 tab = 48828125;
const __int128 MAX = 3725290298461914062;

__int128 parse(string &s)
{
	__int128 res = 0;
	int t = 11;
	bool frac = false;
	int i;
	for (i = 0; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			frac = true;
			continue;
		}
		if (s[i] == 'B')
			res = res * 5 - 2;
		else if (s[i] == 'A')
			res = res * 5 - 2;
		else if ('0' <= s[i] && s[i] <= '9')
			res = res * 5 + (s[i] - '0');
		else break;

		if (frac) --t;
	}
	s.erase(0, i);
	while (t--) res *= 5;
	
	return res;
}

string pack(__int128 x)
{
	string res;
	for (int i = 0; i < 27; ++i)
	{
		int h = (x % 5);
		if (h > +2) h -= 5;
		if (h < -2) h += 5;
		if (h < 0)
			res += char('A' - h - 1);
		else
			res += char('0' + h);

		x = (x - h) / 5;
	}
	reverse(res.begin(), res.end());

	return res;
}

bool ok = true;
stack<__int128> stk;

__int128 myabs(__int128 x)
{
	return (x > 0 ? x : -x);
}

bool add()
{
	if (stk.empty()) return ok = false;
	__int128 b = stk.top(); stk.pop();
	if (stk.empty()) return ok = false;
	__int128 a = stk.top(); stk.pop();

	__int128 res = a + b;
	if (myabs(res) > MAX) return ok = false;

	stk.push(res);
	return true;
}

bool subtract()
{
	if (stk.empty()) return ok = false;
	__int128 b = stk.top(); stk.pop();
	if (stk.empty()) return ok = false;
	__int128 a = stk.top(); stk.pop();

	__int128 res = a - b;
	if (myabs(res) > MAX) return ok = false;

	stk.push(res);
	return true;
}

bool multiply()
{
	if (stk.empty()) return ok = false;
	__int128 b = stk.top(); stk.pop();
	if (stk.empty()) return ok = false;
	__int128 a = stk.top(); stk.pop();

	__int128 res = (__int128)(round(a * b / tab + (long double)((a * b) % tab) / (long double)(tab)));
	if (myabs(res) > MAX) return ok = false;

	stk.push(res);
	return true;
}

bool divide()
{
	if (stk.empty()) return ok = false;
	__int128 b = stk.top(); stk.pop();
	if (stk.empty()) return ok = false;
	__int128 a = stk.top(); stk.pop();
	if (b == 0) return ok = false;

	__int128 res = a * tab / b ;
	if (myabs(res) > MAX) return ok = false;

	stk.push(res);
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
	bool half = false;
	while (cin >> s)
	{
		if (('A' <= s[0] && s[0] <= 'B') || ('0' <= s[0] && s[0] <= '9'))
		{
			if (half)
				ok = false;
			else
				stk.push(parse(s));
		}
		if (ok && s.size())
		{
			half = true;
			for (auto& i : s)
			{
				if (i == '+')
					if (!add())
						break;
				if (i == '-')
					if (!subtract())
						break;
				if (i == '*')
					if (!multiply())
						break;
				if (i == '/')
					if (!divide())
						break;
			}
		}

		if (!ok) 
			break;
	}

	if (ok && stk.size() == 1)
		cout << pack(stk.top()) << '\n';
	else
		cout << "ERROR\n";

	return 0;
}