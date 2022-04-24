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

	int a, b;
	fin >> a >> b;
	int min1{max(a / 2, (a + 1) / 2)}, min2{ max(b / 2, (b + 1) / 2) }, max1{ a }, max2{ b };
	fout << max(min1, min2) << ' ' << min(max1, max2);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}