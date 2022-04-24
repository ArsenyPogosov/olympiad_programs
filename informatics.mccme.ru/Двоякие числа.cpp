#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

bool dvo(int a)
{
	vector<int> Cnum(10, 0);
	while (a > 0)
	{
		++Cnum[a % 10];
		a /= 10;
	}
	int count{ 0 };
	for (auto& i : Cnum)
		if (i > 0) ++count;
	if (count <= 2) 
		return true;

	return false;
}
int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int N;
	fin >> N;
	int minR{ N }, minL{N};
	while (!dvo(minR)) ++minR;
	while (!dvo(minL)) --minL;

	if (minR - N < N - minL) fout << minR;
	else fout << minL;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}