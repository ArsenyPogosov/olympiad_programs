#include <fstream>
//#include <vector>
#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
#include <stack>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	stack<int> t, a2;
	queue<int> a1;
	queue<pair<int, int>> alg;
	int n;
	fin >> n;
	int h;
	for (int i = 0; i <= n - 1; ++i)
	{
		fin >> h;
		a1.push(h);
	}
	bool a;
	while (!a1.empty())
	{
		a = true;
		t.push(a1.front());
		a1.pop();
		alg.push({ 1, 1 });
		if (t.top() == 1)
		{
			a2.push(1);
			t.pop();
			alg.push({ 2, 1 });
		}
		while (a)
		{
			a = false;
			if (!a2.empty() && !t.empty())
				if (t.top() == a2.top() + 1)
				{
					a2.push(t.top());
					t.pop();
					alg.push({ 2, 1 });
					a = true;
				}
		}
	}
	if (a2.top() != n) fout << 0;
	else
		while (!alg.empty())
		{
			fout << alg.front().first << ' ' << alg.front().second << '\n';
			alg.pop();
		}
	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}