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
	ifstream fin("printer.in");	 //open input file
	ofstream fout("printer.out"); //open output file

	int n, m;
	fin >> n >> m;
	if (m <= n * 2)
		fout << "YES";
	else
		fout << "NO";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}