#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int WTD, N, a, b, c;
	fin >> WTD >> N >> a >> b >> c;
	if (WTD == 1) fout << max(0, a + b + c - N * 2);
	else fout << min(a, min(b, c));

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}