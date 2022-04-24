#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	int first{ -1 };
	for(int i = 2; i < sqrt(n) + 1; ++i)
		if ((n % i == 0) && (n != i)) { first = i; break; }
	if (first == -1)
		fout << "NO";
	else {
		if (n / first == first) fout << "NO";
		else {
			int second{ -1 };
			for (int i = 2; i < sqrt(n / first) + 1; ++i)
				if (((n / first) % i == 0) && ((n / first) != i)) { second = i; break; }
			if (second != -1)
				fout << "NO";
			else
				fout << "YES";
		}
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}