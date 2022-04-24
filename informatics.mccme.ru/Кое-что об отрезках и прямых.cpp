#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

bool eqFrac(pair<int, int> a, pair<int, int> b)
{
	return a.first*b.second == a.second*b.first;
}

bool eqLines(pair<pair<int, int>, pair<int, int>> a,
	pair<pair<int, int>, pair<int, int>> b)
{
	return eqFrac(a.first, b.first) && eqFrac(a.second, b.second);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	list<pair<int, int>> points(n);
	int count{ 0 };
	for (auto& i : points) fin >> i.first >> i.second;
	list<list<pair<int, int>>::iterator> ToDelPoint;
	for (list<pair<int, int>>::iterator i = points.begin(); i != points.end(); ++i)
	{
		for (list<pair<int, int>>::iterator j = i; j != points.end(); ++j)
		{
			if (i != j)
				if (*i == *j)
				{
					if (find(ToDelPoint.begin(), ToDelPoint.end(), j) == ToDelPoint.end())
						ToDelPoint.push_back(j);
					++count;
				}
		}
	}
	while (!ToDelPoint.empty()) { points.erase(ToDelPoint.front()); ToDelPoint.pop_front(); }

	fout << count << ' ';
	list<pair<pair<int, int>, pair<int, int>>> lines;
	for (list<pair<int, int>>::iterator i = points.begin(); i != points.end(); ++i)
		for (list<pair<int, int>>::iterator j = i; j != points.end(); ++j)
			if (i != j)
				lines.push_back({ {abs(i->second - j->second), abs(i->first - j->first)},
							{ i->second*abs(i->first - j->first) - abs(i->second - j->second)*i->second,
							  abs(i->first - j->first) } });

	list<list<pair<pair<int, int>, pair<int, int>>>::iterator> ToDelLine; 
	for (list<pair<pair<int, int>, pair<int, int>>>::iterator i = lines.begin(); i != lines.end(); ++i)
	{
		for (list<pair<pair<int, int>, pair<int, int>>>::iterator j = i; j != lines.end(); ++j)
		{
			if (i != j)
				if (eqLines(*i, *j))
				{
					if (find(ToDelLine.begin(), ToDelLine.end(), j) == ToDelLine.end())
						ToDelLine.push_back(j);
					++count;
				}
		}
	}
	while (!ToDelLine.empty()) { lines.erase(ToDelLine.front()); ToDelLine.pop_front(); }

	count = 0;
	for (list<pair<pair<int, int>, pair<int, int>>>::iterator i = lines.begin(); i != lines.end(); ++i)
		for (list<pair<pair<int, int>, pair<int, int>>>::iterator j = i; j != lines.end(); ++j)
			if (i != j)
				if (eqFrac(i->first, j->first))
					++count;
	fout << count << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}