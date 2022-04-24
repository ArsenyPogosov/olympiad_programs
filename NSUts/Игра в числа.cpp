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
	fin >> n;
	bool flag{ true };
	for (int i = 5; i <= 9; ++i)
		if (6 * (2 * i - 5) / 2.0 == n)
		{
			for (int j = i; j >= i - 5; --j)
				fout << j;
			flag = false;
		}

	if (flag)
		fout << "impossible";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}