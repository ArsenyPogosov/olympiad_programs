#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	int h1, a1, h2, a2;
	cin >> h1 >> a1 >> h2 >> a2;
	int ToKill1{ h2 / a1 }, ToKill2{ h1 / a2 };
	if (h2 % a1 != 0) ++ToKill1;
	if (h1 % a2 != 0) ++ToKill2;
	if (ToKill1 <= ToKill2)
		cout << "Bandergolf Cyberswitch";
	else
		cout << "Benadryl Cabbagepatch";

	return 0;
}