#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> posled;
int nn;
ofstream fout("output.txt"); //open output file

void answ(int n, int k, int pos, int min1)
{
	if (k == 1) 
	{
		int sum{ 0 };
		for (auto& i : posled) sum += i; 
		if (sum >= nn||nn-sum>min1) return;
		for (auto& i : posled) fout << i << "  + ";
		fout << nn-sum <<'\n';
		return;
	}
	for (posled[pos] = 1; posled[pos] <= (n - k + 1) && posled[pos] <= min1; ++posled[pos]) answ(n - posled[pos], k - 1, pos + 1, min(min1, posled[pos]));
}

int main()
{
	ifstream fin("input.txt");	 //open input file

	int k;
	fin >> nn >> k;
	posled.resize(k-1, 0);
	answ(nn, k, 0, nn);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}