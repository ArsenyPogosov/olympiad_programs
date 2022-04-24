#include <fstream>
#include <vector>
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
	vector<long long> x(n), y(n);
	for (long long i = 0; i < n; ++i)
		fin >> x[i] >> y[i];
	long long X{ 0 }, Y{ 0 };
	for (long long i = 0; i < n; ++i) {
		X += x[i]; Y += y[i];
	}

	long long ANS{ 0 };
	for (long long i = 0; i < n; ++i) {
		ANS += x[i] * x[i] * (n - 1) - x[i] * (X - x[i]);
		ANS += y[i] * y[i] * (n - 1) - y[i] * (Y - y[i]);
	}
	fout << ANS;
	
	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}