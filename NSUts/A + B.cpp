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

	int a, b;
	fin >> a >> b;
	fout << a + b;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}