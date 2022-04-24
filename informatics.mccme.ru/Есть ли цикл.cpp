#include <fstream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> BidloHod; 
vector<list<int>> Gr;
vector<int> LuckHeIsYourFather;

int MegaDFS(int k)
{
	BidloHod[k] = 1;

	int hhhh;
	for (auto& i : Gr[k])
		if (BidloHod[i] != 2)
		{
			LuckHeIsYourFather[i] = k;
			if (BidloHod[i] == 1) { BidloHod[k] = 2; return i; }
			hhhh = MegaDFS(i);
			if (hhhh != -123) { BidloHod[k] = 2; return hhhh;  }
		}

	BidloHod[k] = 2;
	return -123;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	Gr.resize(n, list<int>(0));
	int h;
	for (auto& i: Gr)
		for (int j = 0; j <= n - 1; ++j)
		{
			fin >> h;
			if (h == 1) i.push_back(j);
		}

	BidloHod.resize(n, 0);
	LuckHeIsYourFather.resize(n, -123);
	int res{ -123 };
	for (int i = 0; i <= n - 1; ++i)
		if (BidloHod[i] == 0)
		{
			res = MegaDFS(i);
			if (res != -123) break;
		}

	fout << res + 1<< ' ';
	int tek{ LuckHeIsYourFather[res] };
	while (tek != res)
	{
		fout << tek + 1<< ' ';
		tek = LuckHeIsYourFather[tek];
	}


	res = -123 ;
	for (int i = 0; i <= n - 1; ++i)
		if (BidloHod[i] == 0)
		{
			res = MegaDFS(i);
			if (res != -123) break;
		}

	fout << res + 1 << ' ';
	tek = { LuckHeIsYourFather[res] };
	while (tek != res)
	{
		fout << tek + 1 << ' ';
		tek = LuckHeIsYourFather[tek];
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}