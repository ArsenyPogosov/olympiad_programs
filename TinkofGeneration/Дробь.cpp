#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int GCD(int a, int b)
{
	return (a ? GCD(b % a, a) : b);
}

void maketurn(int& a, int& b, char c)
{
	if (c == 'A') --a;
	if (c == 'B') --b;
	int d = GCD(a, b); a /= d; b /= d;
}

char choose(int& a, int& b)
{
	if (a % 2) return 'B';
	return 'A';
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b; cin >> a >> b;

	string s;
	while (true)
	{
		char c = choose(a, b);
		cout << c << endl;
		maketurn(a, b, c);
		cin >> s;
		if (s.size() != 1)
			break;
		maketurn(a, b, s[0]);
	}

	return 0;
}