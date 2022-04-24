#include <fstream>
//#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	list<pair<int, int>> points{};
	int h1, h2;
	for (int i = 0; i <= n - 1; ++i)
	{
		fin >> h1 >> h2;
		points.push_back({ h1, h2 });
	}
	points.sort();
	points.push_front({ -1999999999, -1 });

	list<pair<double, int>> TimeLine{};
	TimeLine.push_back({ 0, 0 });
	list<pair<int, int>>::iterator it, help, help2, preEnd;
	it = points.begin();
	preEnd = points.end(); --preEnd;
	while (it != points.end())
	{
		help = it;
		++help;
		if ((it->second == 1) && (help->second == -1))
		{
			TimeLine.push_back({ (help->first - it->first) / double(2), 2 });
			help2 = it;
			--help2;
			points.erase(it);
			points.erase(help);
			it = help2;
		}
		else
			++it;

		preEnd = points.end(); --preEnd;
	}
	TimeLine.push_back({ 1999999999, 0 });
	TimeLine.sort();
	int k, time;
	fin >> k;
	
	list<pair<double, int>>::iterator it2{TimeLine.begin()};
	int count{ n };
	for (int i = 0; i <= k - 1; ++i)
	{
		fin >> time;
		while (it2->first <= time)
		{
			count -= it2->second;
			++it2;
		}
		fout << count << '\n';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}