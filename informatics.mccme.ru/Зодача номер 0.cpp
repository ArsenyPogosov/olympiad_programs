#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

class vector
{
public:
	double x, y;
	vector()
	{
		x = 0; y = 0;
	}
	vector(double _x, double _y)
	{
		x = _x; y = _y;
	}
	vector(const vector& neww)
	{
		*this = neww;
	}
	double size()
	{
		return sqrt(x*x + y*y);
	}
	double OXangel()
	{
		return atan2(y, x);
	}
	const double operator*(const vector& vec)
	{
		return x*vec.x + y*vec.y;
	}
	const double operatorx(const vector& vec)
	{
		return x*vec.x + y*vec.y;
	}
};

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	vector Vec1(2, 2), Vec2;
	Vec2 = vector(2, 4);
	fout << Vec1 x Vec2;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}