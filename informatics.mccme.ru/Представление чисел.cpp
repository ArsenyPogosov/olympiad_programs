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

	int n, p = -1;
	fin >> n;
	for (int i = 2; i*i <= n; ++i)
		if (n % i == 0) { p = i; break; }
	if (p == -1)
		fout << 1 << ' ' << n - 1;
	else
		fout << n / p << ' ' << n - n / p;


	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}