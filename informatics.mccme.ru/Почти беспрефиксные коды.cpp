#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

vector<string> solve(vector<string> Codes, vector<string> prefics, int k)
{
	if (Codes.size() == 0) return{};
	if (k == 0)
	{
		vector<string> res(0);
		vector<string> NewCodes;
		NewCodes.reserve(Codes.size() + 10);
		if (NewCodes.empty())
		{
			NewCodes.push_back(Codes[0]);
		}

		for (int i = 1; i <= Codes.size() - 1; ++i)
		{
			if (NewCodes[0][0] == Codes[i][0])
			{
				NewCodes.push_back(Codes[i]);
			}
			else
			{
				res.push_back(prefics[0] + NewCodes[0]);
				NewCodes.clear();
			}

			if (NewCodes.empty())
			{
				NewCodes.push_back(Codes[i]);
				continue;
			}
		}

		if (!NewCodes.empty())
		{
			res.push_back(prefics[0] + NewCodes[0]);
			NewCodes.clear();
		}

		return res;
	}

	vector<string> res(0), ret;
	vector<string> NewCodes, pref;
	NewCodes.reserve(Codes.size() + 10);
	pref.reserve(Codes.size() + 10);
	if (NewCodes.empty())
	{
		NewCodes.push_back(Codes[0].substr(1));
		pref.push_back(prefics[0]+Codes[0][0]);
	}

	for (int i = 1; i <= Codes.size() - 1; ++i)
	{
		if (NewCodes[0][0] == Codes[i][1])
		{
			NewCodes.push_back(Codes[i].substr(1));
			pref.push_back(prefics[i]+Codes[i][0]);
		}
		else
		{
			ret = solve(NewCodes, pref, k-1);
			res.insert(res.end(), ret.begin(), ret.end());
			NewCodes.clear();
			pref.clear();
		}

		if (NewCodes.empty()) 
		{
			NewCodes.push_back(Codes[i].substr(1)); 
			pref.push_back(prefics[i] +Codes[i][0]);  
			continue; 
		}
	}

	if (!NewCodes.empty())
	{
		ret = solve(NewCodes, pref, k - 1);
		res.insert(res.end(), ret.begin(), ret.end());
		NewCodes.clear();
	}

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	vector<string> Codes(0), ans2(0);
	Codes.reserve(n + 10); ans2.reserve(n + 10);
	string str;
	for (int i = 0; i <= n - 1; ++i)
	{
		fin >> str;
		if (str.size() <= m) ans2.push_back(str);
		else Codes.push_back(str);
	}

	sort(Codes.begin(), Codes.end());
	vector<string> h(Codes.size(), "");
	vector<string> ans{ solve(Codes, h, m) };
	fout << ans.size()+ans2.size() << '\n';
	for (auto& i : ans)
		fout << i << '\n';
	for (auto& i : ans2)
		fout << i << '\n';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}