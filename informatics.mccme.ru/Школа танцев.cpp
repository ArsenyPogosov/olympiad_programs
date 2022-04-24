#include <fstream>
#include <vector>
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

	long long n;
	fin >> n;

	vector<long long> cMNum(n * 2 + 2, 0);
	long long mNum = 1;
	++cMNum[mNum + n];
	for (long long i = 0; i <= n - 1; ++i)
	{
		char h;
		fin >> h;
		if (h == 'a')
			++mNum;
		else
			--mNum;

		++cMNum[mNum + n];
	}

	long long ans = 0;
	for (auto&i : cMNum) ans += i*(i - 1) / 2;
	fout << ans;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}