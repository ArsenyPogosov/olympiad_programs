#include <fstream>
#include <vector>
//#include <queue>
#include <stack>
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
	vector<int> map(n);
	for (auto&i : map)
		fin >> i;
	vector<int> ans(n, -1);
	stack<int> table;
	for (int i = n - 1; i >= 0; --i)
	{
		while ((!table.empty()) && (map[table.top()] >= map[i]))
			table.pop();
		if (table.empty())
		{
			ans[i] = -1;
			table.push(i);
			continue;
		}
		ans[i] = table.top();
		table.push(i);
	}
	for (auto&i : ans)
		fout << i << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}