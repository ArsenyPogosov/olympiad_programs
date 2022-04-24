#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int v, t, r, w;
	fin >> v >> t >> r >> w;
	vector<vector<int>> Rains(r, vector<int>(3));
	vector<vector<int>> Cross(r, vector<int>(2));
	for (auto& i : Rains)
		fin >> i[0] >> i[1] >> i[2];
	for (auto& i : Cross)
		fin >> i[0] >> i[1];

	int Time{ 0 }, WaterV{ 0 };
	bool flag{ false };
	while (Time <= t)
	{
		auto& hIt = *Cross.begin();
		for (auto& i : Cross)
		{
			if (i[0] <= WaterV && hIt[0] <= i[0])
				hIt = i;
		}
		WaterV -= hIt[1];

		for (auto& i : Rains)
		{
			if (i[0] <= Time && Time <= i[1]-1) WaterV += i[2];
		}

		WaterV = max(WaterV, 0);
		if (WaterV >= v)
			flag = true;
		if (flag)
			break;

		++Time;
	}
	if (flag)
		fout << "NO";
	else
		fout << WaterV;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}