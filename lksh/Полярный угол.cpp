#include <iostream>
#include <iomanip>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

const double pi = 3.1415926535897932384626433832795;

int main()
{
	double x, y;
	cin >> x >> y;
	double res = atan2(y, x);
	if (res < 0)
		res += pi * 2;
	cout << setprecision(20) << res;

	return 0;
}