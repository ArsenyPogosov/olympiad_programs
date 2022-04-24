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

	int n, x;
	fin >> n >> x;
	vector<int> map(n), map2(n);
	for (auto&i : map)
		fin >> i;
	for (auto&i : map2)
		fin >> i;
	deque<int> best;
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((!best.empty()) && (map2[best.back()] <= map2[i]))
			best.pop_back();
		best.push_back(i);
	}
	pair<int, int> choose{ -2, -2 };
	int SuperH;
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((!best.empty()) && (best.front() <= i))
			best.pop_front();
		if (best.empty())
			break;
		if (choose == pair<int, int>{-2, -2})
			SuperH = x;
		else
			SuperH = x%map[choose.first] + x / map[choose.first] * map2[choose.second];
		if (x%map[i] + x / map[i] * map2[best.front()] > SuperH)
			choose = { i, best.front() };
	}

	if (choose == pair<int, int>{-2, -2})
		SuperH = x;
	else
		SuperH = x%map[choose.first] + x / map[choose.first] * map2[choose.second];
	fout << SuperH << '\n';
	fout << choose.first + 1 << ' ' << choose.second + 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}