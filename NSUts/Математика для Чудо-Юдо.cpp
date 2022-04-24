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
	ifstream fin("addend.in");	 //open input file
	ofstream fout("addend.out"); //open output file

	long long N;
	fin >> N;
	fout << N / 2 + 1;


	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}