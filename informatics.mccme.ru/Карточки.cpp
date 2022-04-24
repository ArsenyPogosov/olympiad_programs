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

	long long fact[16];
	fact[0] = 1;
	for (long long i = 1; i < 16; ++i)
		fact[i] = fact[i - 1] * i;
	int HowMuch['z' - 'a' + 1];
	for (int i = 0; i < 'z' - 'a' + 1; ++i)
		HowMuch[i] = 0;
	string s;
	fin >> s;
	long long res{fact[s.size()]};
	for (auto&i : s)
		++HowMuch[i - 'a'];
	for (auto&i : HowMuch)
		res /= fact[i];
	fout << res;


	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}