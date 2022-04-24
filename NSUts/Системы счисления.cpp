#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int q, n;
	fin >> q >> n;
	string answ{ "" };
	while (n != 0)
	{
		answ = char('0' + n % q) + answ;
		n /= q;
	}
	fout << answ;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}