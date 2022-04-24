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

	int n;
	fin >> n;
	vector<long long> mass(n);
	vector<long long> a(n);
	for (auto&i : mass)
		fin >> i;
	a[0] = mass[0];
	for (int i = 1; i <= n - 1; ++i)
		a[i] = a[i - 1] + mass[i];
	deque<int> best;
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((!best.empty()) && (a[best.back()] < a[i]))
			best.pop_back();
		best.push_back(i);
	}
	pair<int, int> choose{ 0, 0 };
	int SuperH1, SuperH2;
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((!best.empty()) && (best.front() < i))
			best.pop_front();
		if (best.empty())
			break;
		if (i > 0)
			SuperH1 = a[best.front()] - a[i - 1];
		else
			SuperH1 = a[best.front()];

		if (choose.first > 0)
			SuperH2 = a[choose.second] - a[choose.first - 1];
		else
			SuperH2 = a[choose.second];
		if (SuperH1 >= SuperH2)
			choose = { i, best.front() };
	}

	fout << choose.first + 1 << '\n' << choose.second + 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}