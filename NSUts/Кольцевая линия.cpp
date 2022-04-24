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
	if (n % 2 == 0)
		fout << n*(n - 2);
	else
		fout << n*(n - 1);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}