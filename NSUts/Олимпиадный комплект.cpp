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

	int computer, table, chair, pan, notebook;
	fin >> computer >> table >> chair >> pan >> notebook;
	fout << min(min(min(min(pan / 3, notebook / 3), chair / 3), table / 2), computer);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}