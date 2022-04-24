#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
using namespace std;

long long GCD(long long a, long long b)
{
	int h;
	if (a < b)
	{
		h = a;
		a = b;
		b = h;
	}

	if (a == 0)
		return b;
	else
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
}

long long LCM(long long a, long long b)
{
	return a*b / GCD(a, b);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	long long T, N, M;
	fin >> T >> N >> M;
	long long lcm = LCM(N, M);
	long long YersToT{ T / lcm };
	if (lcm*YersToT < T) ++YersToT;
	fout << lcm*YersToT/N;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}