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

	int n, ost = 0, ans = -1;
	fin >> n;
	for (int i = 1; i <= n; ++i)
	{
		ost = (ost * 10 + 1) % n;
		if (ost == 0)
		{
			ans = i;
			break;
		}
	}
	if (ans == -1)
		fout << "NO";
	else
		for (int i = 0; i < ans; ++i) fout << 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}