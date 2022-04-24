#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> DSU;
vector<int> length;

void create(int x)
{
	DSU[x] = x;
	length[x] = 1;
}

int find(int x)
{
	if (DSU[x] == x) return x;

	return DSU[x] = find(DSU[x]);
}

int cnt{ 0 };

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) ++cnt;
	if (length[x] >= length[y])
	{
		DSU[y] = x;
		length[x] += length[y];
		length[y] = 0;
	}
	else
	{
		DSU[x] = y;
		length[y] += length[x];
		length[x] = 0;
	}
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	DSU.resize(n);
	length.resize(n);
	for (int i = 0; i < n; ++i)
		create(i);
	for (int i = 0; i < m; ++i)
	{
		int a, b; fin >> a >> b; --a; --b;

		merge(a, b);
		if (cnt == n - 1) { fout << i + 1; break; }
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}