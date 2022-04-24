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

	int n;
	fin >> n;
	int p = 2;
	string ans = "";
	while (n != 1)
	{
		if (p*p > n) { ans += '*' + to_string(n); break; }
		int count = 0;
		while (n % p == 0)
		{
			++count;
			n /= p;
		}
		if (count == 1) ans += '*' + to_string(p);
		if (count >= 2) ans += '*' + to_string(p) + '^' + to_string(count);
		++p;
	}
	ans.erase(0, 1);
	fout << ans;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}