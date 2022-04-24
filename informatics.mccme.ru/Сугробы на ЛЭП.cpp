#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int Nearest(int n)
{
	int res{ 1 };
	while (res < n) res *= 2;

	return res;
}

struct node {
	long long sum;
	long long toAdd;
};
vector<node> tree;

void relax(int x, int l, int r)
{
	tree[2 * x].sum += (r - l + 1) / 2 * tree[x].toAdd;
	tree[2 * x].toAdd += tree[x].toAdd;
	tree[2 * x + 1].sum += (r - l + 1) / 2 * tree[x].toAdd;
	tree[2 * x + 1].toAdd += tree[x].toAdd;
	tree[x].toAdd = 0;
}

void Change(int x, int l, int r, int a, int b, long long v)
{
	if ((r < a) || (b < l)) return;
	if ((a <= l) && (r <= b))
	{
		tree[x].sum += (r - l + 1)*v;
		tree[x].toAdd += v;
		return;
	}
	relax(x, l, r);
	Change(x * 2, l, (l + r) / 2, a, b, v);
	Change(x * 2 + 1, (l + r) / 2 + 1, r, a, b, v);
	tree[x].sum = tree[x * 2].sum + tree[x * 2 + 1].sum;
}

long long SumInTree(int x, int l, int r, int a, int b)
{
	if ((r < a) || (b < l)) return 0;
	if ((a <= l) && (r <= b)) return tree[x].sum;

	relax(x, l, r);
	return SumInTree(x * 2, l, (l + r) / 2, a, b) +
		   SumInTree(x * 2 + 1, (l + r) / 2 + 1, r, a, b);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n; n = Nearest(n);
	tree.resize(n * 2 + 1, {0, 0});

	int k; fin >> k;
	for (int i = 0; i < k; ++i)
	{
		int a; fin >> a;
		if (a == 1)
		{
			int b, c, d; fin >> b >> c >> d; ++b; ++c;
			Change(1, 1, n, b, c - 1, d);
		}
		else
		{
			int b, c; fin >> b >> c; ++b; ++c;
			fout << SumInTree(1, 1, n, b, c - 1) << '\n';
		}
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}