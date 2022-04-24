#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <cmath>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<int> JustVector(n);
	for (auto& i : JustVector) fin >> i;
	sort(JustVector.begin(), JustVector.end());
	for (auto& i : JustVector) fout << i << ' ';


	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}