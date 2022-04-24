#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	if (n == 1)
	{
		cout << "Ivan Urgant\nDraw\n";
		return 0;
	}
	if (n == 2)
	{
		cout << "Ivan Safonov\n";
		return 0;
	}
	if (n == 3)
	{
		cout << "Ivan Urgant\nDraw\n";
		return 0;
	}
	if (n == 4)
	{
		cout << "Ivan Urgant\nMix\n";
		return 0;
	}
	if (n % 2 == 0)
	{
		cout << "Ivan Urgant\nDraw\n";
		return 0;
	}
	if (n % 2 == 1)
	{
		cout << "Ivan Safonov\n";
		return 0;
	}

	return 0;
}
//229