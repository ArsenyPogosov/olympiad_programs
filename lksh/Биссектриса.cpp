#include <iostream>
#include <iomanip>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

vector<double> line(double x1, double y1, double x2, double y2)
{
	return{ y2 - y1, x1 - x2, -(y2 - y1) * x1 - (x1 - x2) * y1 };
}

pair<double, double> vec(double fi)
{
	return{ cos(fi), sin(fi) };
}

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	x4 = x1 + vec((atan2(y2 - y1, x2 - x1) + atan2(y3 - y1, x3 - x1)) / 2).first;
	y4 = y1 + vec((atan2(y2 - y1, x2 - x1) + atan2(y3 - y1, x3 - x1)) / 2).second;
	for (auto&i : line(x1, y1, x4, y4))
		cout << setprecision(6) << i << ' ';

	return 0;
}