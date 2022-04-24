#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string a, b;
	fin >> a >> b;
	vector<int> TotalSum228(a.size());
	TotalSum228[0] = a[0] - '0';
	for (int i = 1; i <= a.size() - 1; ++i)
		TotalSum228[i] = TotalSum228[i-1] + a[i] - '0';
	vector<bool> IsPref(b.size(), false), IsSuf(b.size(), false);
	for (int i = 0; i <= b.size() - 1; ++i)
		if (a[i] == b[i])
			IsPref[i] = true;
		else
			break;
	for (int i = 0; i <= b.size()-1; ++i)
		if (a[a.size()-1-i] == b[b.size() - 1 - i])
			IsSuf[b.size() - 1 - i] = true;
		else
			break;
	int SumKa{ 0 }, aaa, bbb;
	for (int i = 0; i <= b.size() - 1; ++i)
		for (int j = 1; (j <= 7) && (i + j - 1 <= b.size() - 1); ++j)
		{
			if ((i != 0) && (!IsPref[i - 1]))
				continue;
			if ((i+j-1 != b.size() - 1) && (!IsSuf[i + j]))
				continue;
			SumKa = 0;
			for (int k = 0; k <= j - 1; ++k)
				SumKa = SumKa*10 + b[i + k] - '0';
			if (i != 0)
				if (SumKa != TotalSum228[a.size()-1-((b.size()-1)-i-j+1+1)+1] - TotalSum228[i - 1])
					continue;
			if (i == 0)
				if (SumKa != TotalSum228[a.size() - 1 - ((b.size() - 1) - i - j + 1 + 1) + 1])
					continue;

			aaa = i; bbb = a.size() - 1 - ((b.size() - 1) - i - j + 1 + 1) + 1; break;
		}
	fout << aaa + 1 << ' ' << bbb + 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}