#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int a, b, c;
bool Consid(vector<long long> test, vector<long long> element)
{
	bool flag = true;
	for (int i = 0; i <= test.size()-1; ++i)
		if (((~element[i]&test[i]))!=0) { flag = false; break; }

	return flag;
}

vector<long long> bits(string s)
{
	vector<long long> res;
	while (s != "")
	{
		long long tekres{0};
		for (int i = 0; i <= min(63, (int)s.size()); ++i)
		{
			if (s[i] == '1') tekres += pow(2, i);
		}
		s.erase(0, min(63, (int)s.size()));

		res.push_back(tekres);
	}

	return res;
}
int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	fin >> a >> b >> c;
	string h;
	vector<pair<string, vector<long long>>> Elem(a, {"", vector<long long>(c/64+1)});
	for (auto& i : Elem)
	{
		fin >> h >> i.first;
		i.second = bits(h);
	}
	sort(Elem.begin(), Elem.end());
	vector<vector<long long>> Tests(b);

	for (auto& i : Tests)
	{
		fin >> h;
		i = bits(h);
	}

	string answ;
	for (auto& i : Tests)
	{
		answ = "";
		for (auto& j : Elem)
		{
			if (Consid(i, j.second)) answ += j.first + ',';
		}

		if (answ != "")
			answ.pop_back();
		else answ = "unknown";

		fout << answ << '\n';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}