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
	bool prime = true;
	fin >> n;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) { prime = false; break; }
	if (n == 1) prime = false;
	if (prime)
		fout << "prime";
	else
		fout << "composite";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}