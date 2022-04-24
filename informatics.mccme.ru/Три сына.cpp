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

	int n;
	fin >> n;
	int r{ n % 3 };
	n -= r;
	if (r == 0)
		fout << (n - 3) / 3 << ' ' << (n - 3) / 3 + 1 << ' ' << (n - 3) / 3 + 2;
	if (r == 1)
		fout << (n - 3) / 3 << ' ' << (n - 3) / 3 + 1 << ' ' << (n - 3) / 3 + 2 + 1;
	if (r == 2)
		fout << (n - 3) / 3 << ' ' << (n - 3) / 3 + 1 + 1<< ' ' << (n - 3) / 3 + 2 + 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}