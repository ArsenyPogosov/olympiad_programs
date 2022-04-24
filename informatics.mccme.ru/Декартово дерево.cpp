#include <iostream>
#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

struct node {
	int x; pair<int, int> y;
	node *l;
	node *r;
	node() {}
	node(int _x, pair<int, int> _y) { x = _x; y = _y; l = r = NULL; }
};

void Split(node *&treap, int key, node *&l, node *&r)
{
	if (treap == NULL)
	{
		l = r = NULL;
		return;
	}

	if (treap->x > key)
	{
		Split(treap->l, key, l, treap->l);
		r = treap;
		return;
	}
	if (treap->x < key)
	{
		Split(treap->r, key, treap->r, r);
		l = treap;
		return;
	}
}

void Insert(node *&treap, node *el)
{
	if (treap == NULL)
	{
		treap = el;
		return;
	}

	if (el->y > treap->y)
	{
		Split(treap, el->x, el->l, el->r);
		treap = el;
		return;
	}
	if (el->y < treap->y)
	{
		if (el->x > treap->x)
			Insert(treap->r, el);
		if (el->x < treap->x)
			Insert(treap->l, el);
		return;
	}
}

vector<vector<int>> ANS;

void DFS(node *treap)
{
	if (treap->l != NULL)
	{
		ANS[treap->y.second][1] = treap->l->y.second;
		ANS[treap->l->y.second][0] = treap->y.second;
		DFS(treap->l);
	}
	if (treap->r != NULL)
	{
		ANS[treap->y.second][2] = treap->r->y.second;
		ANS[treap->r->y.second][0] = treap->y.second;
		DFS(treap->r);
	}
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	node *treap = NULL;
	int n;
	fin >> n;
	ANS.resize(n, { -1, -1, -1 });
	for (int i = 0; i < n; ++i)
	{
		int x, y; fin >> x >> y;
		node *h = new node(x, { -y, i });
		Insert(treap, h);
	}

	fout << "YES\n";
	DFS(treap);
	for (auto&i : ANS)
		fout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] + 1 << '\n';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}