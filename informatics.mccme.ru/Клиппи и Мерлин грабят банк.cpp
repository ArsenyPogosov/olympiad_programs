#include <fstream>
#include <vector>
#include <deque>
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

	int n, k;
	fin >> n >> k;
	vector<int> map(n);
	for (auto&i : map)
		fin >> i;
	deque<int> best;
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((!best.empty()) && (map[best.back()] < map[i]))
			best.pop_back();
		best.push_back(i);
	}
	pair<int, int> choose{ 0, n - 1 };
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((!best.empty()) && (best.front() - i - 1 < k))
			best.pop_front();
		if (best.empty())
			break;
		if (map[i] + map[best.front()] > map[choose.first] + map[choose.second])
			choose = { i, best.front() };
	}

	fout << choose.first + 1 << ' ' << choose.second + 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}