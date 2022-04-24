#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> Gir;

vector<vector<int>> loop(vector<int> a1, vector<int> a2, vector<int> a3, int it)
{
	if (it == Gir.size())
	{
		int Sa1{ 0 }, Sa2{ 0 }, Sa3{ 0 };
		for (auto& i : a1) Sa1 += Gir[i];
		for (auto& i : a2) Sa2 += Gir[i];
		for (auto& i : a3) Sa3 += Gir[i];
		if ((Sa1 == Sa2) && (Sa2 == Sa3)) return{ a1, a2, a3 };
		else return{ vector<vector<int>>(0) };
	}
	a1.push_back(it);
	vector<vector<int>> res{ loop(a1, a2, a3, it + 1) };
	if (res != vector<vector<int>>(0)) return res;

	a1.pop_back();
	a2.push_back(it);
	res = loop(a1, a2, a3, it + 1);
	if (res != vector<vector<int>>(0)) return res;

	a2.pop_back();
	a3.push_back(it);
	res = loop(a1, a2, a3, it + 1);
	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	Gir.resize(n);
	for (auto& i : Gir) fin >> i;
	vector<vector<int>> res{ loop({}, {}, {}, 0) };
	if (res == vector<vector<int>>(0))
		fout << "No solution";
	else
		for (auto& i : res)
		{
			for (auto& j : i) fout << j+1 << ' ';
			fout << '\n';
		}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}