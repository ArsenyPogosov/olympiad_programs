#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

pair<long long, long long> GCD2(long long a, long long b)
{
	if (b == 0) return{ 1, 0 };
	auto res = GCD2(b, a % b);
	return{ res.second, res.first - res.second * (a / b) };
}

long long GCD(long long a, long long b)
{
	auto h = GCD2(a, b);
	return a*h.first + b*h.second;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	long long a, b, c;
	fin >> a >> b >> c;
	long long d = GCD(a, b);
	if (c % d != 0)
	{
		fout << "Impossible";
		fin.close();  //close input file
		fout.close(); //close output file

		return 0;
	}
	a /= d;
	b /= d;
	c /= d;
	auto h = GCD2(a, b);
	long long x = h.first*c, y = h.second*c;
	long long k;
	if (x < 0)
		k = (-x - 1) / b + 1;
	else
		k = - x / b;
	x += k * b; y -= k * a;
	fout << x << ' ' << y;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}