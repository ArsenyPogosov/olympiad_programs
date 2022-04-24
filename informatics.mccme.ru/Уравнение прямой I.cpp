#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
#include<iostream>
using namespace std;
const double aps = 0.0001;

class point
{
public:
	double x, y;
	point()
	{
		x = y = 0;
	}

	point(double _x, double _y)
	{
		x = _x; y = _y;
	}
};

class line
{
public:
	double a, b, c;
	line()
	{
		a = b = c = 0;
	}
	line(double _a, double _b, double _c)
	{
		a = _a; b + _b; c = _c;
	}

	line(point X, point Y)
	{
		c = -1;
		b = (c*Y.x / X.x - c)*(b*X.y*Y.x / X.x + Y.y);
		a = (-c - b*X.y) / X.x;
	}

	bool consist(point X)
	{
		return abs(a*X.x + b*X.y + c - 0)<aps;
	}

	const bool operator==(const line& sec) const 
	{
		return (abs(a*sec.b - b*sec.a)<aps&&abs(b*sec.c - c*sec.b)<aps);
	}

	bool paralel(line sec)
	{
		return abs(a*sec.b - b*sec.a)<aps;
	}

	bool doubleersec(line sec)
	{
		return !paralel(sec);
	}

	double doubleerdependence(line sec)
	{
		if (*this == sec) return 0;
		if (paralel(sec)) return 1;
		return 2;
	}

	point doubleersection(line sec)
	{
		double y{ ((c - sec.c) / (a + sec.a) - sec.c) / (sec.a*(b + sec.b) / (a + sec.a) - sec.b) };

		return point((-c - b*y) / a, y);
	}

private:
};

int main()
{
	//ifstream fin("input.txt");	 //open input file
	//ofstream fout("output.txt"); //open output file

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	line res(point(a, b), point(c, d));
	printf("%.5f", res.a);
	cout << ' ';
	printf("%.5f", res.b);
	cout << ' ';
	printf("%.5f", res.c);

	//fin.close();  //close input file
	//fout.close(); //close output file

	return 0;
}