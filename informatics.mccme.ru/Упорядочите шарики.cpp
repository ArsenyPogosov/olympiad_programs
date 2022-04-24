#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<int> Podp(n + 2, 1000000000);
	Podp[0] = -1000000000;
	for (int i = 0; i < n; ++i)
	{
		int a;
		fin >> a;
		*lower_bound(Podp.begin(), Podp.end(), a) = a;
	}
	int i;
	for (i = 0; i < n + 2; ++i)
		if (Podp[i] == 1000000000)
			break;
	--i;

	fout << n - i;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}