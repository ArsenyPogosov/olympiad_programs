#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

long long power(long long x, long long n, long long p)
{
	if (n == 0) return 1;
	if (n % 2 == 1) return power(x, n - 1, p)*x%p;
	long long h = power(x, n / 2, p);
	return h*h%p;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	long long x, n, p;
	fin >> x >> n >> p;
	fout << power(x, n, p);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}