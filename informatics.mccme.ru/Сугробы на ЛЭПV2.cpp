#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

struct treeEl
{
	int sum;
	int Add;
};

vector<treeEl> tree;

void pushUpdate(int v, int lV, int rV)
{
	int m = (lV + rV) / 2;
	tree[v * 2].sum += tree[v].Add*(m-lV+1);
	tree[v * 2 + 1].sum += tree[v].Add*(rV - m - 1 + 1);
	tree[v * 2].Add += tree[v].Add;
	tree[v * 2 + 1].Add += tree[v].Add;
	tree[v].Add = 0;
}

void Update(int v, int lV, int rV, int l, int r, int toAdd)
{
	if (r < lV || rV < l) return;
	if (l <= lV && rV <= r) { tree[v].sum += toAdd*(rV-lV+1); tree[v].Add += toAdd; return; }
	pushUpdate(v, lV, rV);
	int m = (lV + rV) / 2;
	Update(v * 2, lV, m, l, r, toAdd);
	Update(v * 2 + 1, m + 1, rV, l, r, toAdd);
	tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
}

int SumInTree(int v, int lV, int rV, int l, int r)
{
	if (r < lV || rV < l) return 0;
	if (l <= lV && rV <= r) return tree[v].sum;

	pushUpdate(v, lV, rV);
	int m = (lV + rV) / 2;
	return SumInTree(v * 2, lV, m, l, r) + SumInTree(v * 2 + 1, m + 1, rV, l, r);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	tree = vector<treeEl>(n * 4 + 16, {0, 0});
	int command, l, r, s;
	for (int i = 0; i <= m - 1; ++i)
	{
		fin >> command;
		if (command == 1)
		{
			fin >> l >> r >> s;
			Update(1, 0, n - 1, l, r - 1, s);
		}
		if (command == 2)
		{
			fin >> l >> r;
			fout << SumInTree(1, 0, n - 1, l, r - 1) << '\n';
		}
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}