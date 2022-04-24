#include <iostream>
#include <iomanip>
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
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << setprecision(6) << y2 - y1 << ' ' << x1 - x2 << ' ' << -(y2 - y1) * x1 - (x1 - x2) * y1;
	
	return 0;
}