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
	ifstream fin("coins.in");	 //open input file
	ofstream fout("coins.out"); //open output file

	long long n;
	fin >> n;
	long long res = 0;
	for (long long i = 1; i <= n; ++i)
		res += i*i;

	fout << res;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}