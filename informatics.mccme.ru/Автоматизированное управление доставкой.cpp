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

	long long k, x, y;
	fin >> k >> x >> y;
	long long n{ y / x };
	if (y%x <= n*(k - 1))
		fout << y;
	else
		fout << (n + 1)*x;


	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}