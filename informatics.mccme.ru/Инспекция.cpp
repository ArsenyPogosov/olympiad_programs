#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	vector<vector<int>> A(n);
	int a1, a2;
	for (int i = 0; i <= m-1; ++i)
	{
		fin >> a1 >> a2;
		A[a1-1].push_back(a2-1);
	}
	for (auto& i : A) i.erase(unique(i.begin(), i.end()), i.end());
	if (n == 1)
	{
		fout << "-1";
		return 0;
	}
	if (m == 0)
	{
		fout << "2";
		return 0;
	}
	queue<int> Q;
	vector<int> fire(n, 0);
	bool flag{ false };
	bool thero{ false };
	int it{0};

	while (!flag)
	{
		Q.push(it);
		fire[it] = 1;
		while (!Q.empty())
		{
			for (auto& i : A[Q.front()])
			{
				if (fire[i] == 1) { thero = true; break; }
				if (fire[i] == 0) { fire[i] = 1; Q.push(i); }
			}
			Q.pop();
		}
		flag = true;
		for (int i = 0; i <= n-1; ++i)
		{
			if (fire[i] == 1) fire[i] = -1;
			if ((fire[i] == 0) && (flag)) { flag = false; it = i; }
		}
	}
	if (thero) fout << "0";
	else fout << "1";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}