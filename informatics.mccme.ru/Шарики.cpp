#include <fstream>
//#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
#include <queue>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int N;
	fin >> N;
	int h;
	list<int> GB;
	for (int i = 0; i <= N - 1; ++i)
	{
		fin >> h;
		GB.push_back(h);
	}
	queue<int> Q;
	int count, res{ 0 };
	bool check{ true };
	while (check)
	{
		for (auto& i : GB) Q.push(i);
		Q.push(-1);
		GB.clear();
		h = -2;
		count = 0;
		check = false;
		while (Q.size())
		{
			if (Q.front() == h) ++count;
			else
			{
				if (count < 3)
					for (int i = 0; i <= count - 1; ++i) GB.push_back(h);
				else
				{
					check = true;
					res += count;
				}
				h = Q.front();
				count = 1;
			}
			Q.pop();
		}
	}
	fout << res;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}