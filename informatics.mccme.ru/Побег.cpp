#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

bool Bad(int x, int y, int BadX, int BadY)
{
	if (abs(x - BadX) == abs(y - BadY)) 
		return true;

	return false;
}

int main()
{
	int n;
	cin >> n;
	int MyX{1}, MyY;
	cin >> MyY;
	int BadX, BadY;
	cin >> BadX, BadY;

	while (MyY < n)
	{
		++MyY;
		if (MyX - 1 >= 1 && MyX - 1 <= n && !Bad(MyX - 1, MyY, BadX, BadY))
			cout << --MyX << ' ' << MyY << endl;
		else
		if (MyX>= 1 && MyX<= n && !Bad(MyX, MyY, BadX, BadY))
			cout << MyX << ' ' << MyY << endl;
		else
		if (MyX + 1 >= 1 && MyX + 1 <= n && !Bad(MyX + 1, MyY, BadX, BadY))
			cout << ++MyX << ' ' << MyY << endl;
	}
	return 0;
}