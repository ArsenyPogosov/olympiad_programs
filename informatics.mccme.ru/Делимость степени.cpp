#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int pc(int& n, int p)
{
	int count = 0;
	while (n % p == 0)
	{
		n /= p;
		++count;
	}
	return count;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int a, b, n = 1;
	fin >> b >> a;
	for (int i = 2; i * i <= b; ++i)
	{
		int x = pc(a, i), y = pc(b, i);
		if (x == 0 && y != 0) { n = -1; break; }
		if (x == 0 && y == 0) continue;
		n = max(n, (y - 1)/x + 1);
	}
	if (b > 1)
	{
		int i = b;
		int x = pc(a, i), y = pc(b, i);
		if (x == 0 && y != 0) 
			n = -1;
		else
			if (!(x == 0 && y == 0))
				n = max(n, (y - 1) / x + 1);
	}
	fout << n;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}