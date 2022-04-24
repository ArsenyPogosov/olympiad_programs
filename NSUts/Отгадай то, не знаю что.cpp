#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("anything.in");	 //open input file
	ofstream fout("anything.out"); //open output file

	int a, b;
	fin >> a >> b;
	fout << int(round(sqrt(a*a + b*b)));

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}