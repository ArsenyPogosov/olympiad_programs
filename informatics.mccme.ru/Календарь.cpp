#include <fstream>
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
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int y, d;
	fin >> y >> d;
	int days;
	if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
		days = 366;
	else
		days = 365;
	days += d - 1;
	int count;
	count = (days / 7) * 2;
	if (days % 7 == 6)
		++count;
	if (d == 7)
		--count;

	fout << count;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}