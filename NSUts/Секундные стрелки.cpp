#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const double pi = 3.141592653589793238463;

int main()
{
	ifstream fin("seconds.in");	 //open input file
	ofstream fout("seconds.out"); //open output file

	string ss;
	double f, s;
	fin >> f >> ss;
	s = stod(ss);
	f = f*pi / 180;
	int n;
	if (ss.find('.') == string::npos)
		n = 0;
	else
		n = ss.size() - ss.find('.') - 1;
	for (int i = 1; i <= n; ++i)
	{
		s *= 10; f *= 10;
	}
	long long fll = long long(round(f));
	long long sll = long long(round(s));
	if (fll == sll)
		fout << "Same";
	else
	{
		if (s < f)
			fout << "Second";
		else
			fout << "First";
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}