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

	long long n;
	fin >> n;
	fout << (abs(n-1)+1)*(n + 1) / 2;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}