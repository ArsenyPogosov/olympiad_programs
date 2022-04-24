#include <iostream>
#include <string>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b;

	int x, y;
	if (a == "rock")     x = 0;
	if (a == "paper")    x = 1;
	if (a == "scissors") x = 2;
	if (b == "rock")     y = 0;
	if (b == "paper")    y = 1;
	if (b == "scissors") y = 2;

	if (x == (y + 1) % 3)
		cout << "Anna\n";
	if (x == y)
		cout << "Draw\n";
	if (y == (x + 1) % 3)
		cout << "Boris\n";

	return 0;
}