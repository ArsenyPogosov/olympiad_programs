#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

pair<int, int> GCD(int a, int b)
{
	if (b == 0) return{ 1, 0 };
	auto res = GCD(b, a % b);
	return{ res.second, res.first - res.second * (a / b) };
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int a, n;
	fin >> a >> n;
	auto res = GCD(a, n);
	if (res.first*a + res.second*n != 1)
		fout << 0;
	else
		fout << ((res.first % n) + n) % n;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}