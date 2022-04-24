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

	int n;
	fin >> n;
	vector<int> numbers(n);
	for (int i = 0; i <= n - 1; ++i)
		fin >> numbers[i];

	int begin = 0;
	int bbegin = 0, blen = 2, bstep = numbers[1]-numbers[0];
	while(begin <= n - 2)
	{
		int step = numbers[begin + 1] - numbers[begin];
		int end;
		for (end = begin + 1; end <= n - 1; ++end)
		{
			if (numbers[end] - numbers[end - 1] != step)
			{
				--end;
				break;
			}
			if (end == n - 1) break;
		}
		int len = end - begin + 1;
		if ((len > blen) || ((len == blen) && (step > bstep)))
		{
			bbegin = begin;
			blen = len;
			bstep = step;
		}

		begin = end;
	}

	fout << bbegin + 1 << ' ' << blen;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}