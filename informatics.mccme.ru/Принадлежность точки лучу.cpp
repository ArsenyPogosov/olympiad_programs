#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

struct vec 
{
	int x, y;
	vec()
	{
		x = 0; y = 0;
	}
	vec(int _x, int _y)
	{
		x = _x; y = _y;
	}
	friend vec operator-(const vec& b)
	{
		vec res;
		res.x = -b.x; res.y = -b.y;
		return res;
	}
	vec operator+(const vec& b)
	{
		vec res;
		res.x = x+b.x; res.y = y+b.y;
		return res;
	}
	vec operator-(const vec& b)
	{
		return *this + (-b);
	}
	double operator*(const vec& b)
	{
		double res;
		res = x * b.x + y * b.y;
		return res;
	}
	double operator^(const vec& b)
	{
		double res;
		res = x * b.y - y * b.x;
		return res;
	}
	double length()
	{
		return sqrt(x*x + y*y);
	}
};

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int a, b, c, d, e, f;
	fin >> a >> b >> c >> d >> e >> f;
	a -= c; e -= c;
	b -= d; f -= d;
	vec luch(e, f), point(a, b);
	if (((luch^point) == 0)&&(luch*point>=0))
		fout << "YES";
	else
		fout << "NO";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}