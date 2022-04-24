#include <fstream>
#include <vector>
#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int N;

bool Vh(int n)
{
	return (1 <= n) && (n <= N);
}

bool Y(int n)
{
	return (2*N+1 <= n);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int M, h;
	fin >> N >> M >> h;
	vector<int> VhY(2*N+M+1, 0);
	queue<pair<int, int>> Q;
	int h1, h2;
	for (int i = 0; i <= h - 1; ++i)
	{
		fin >> h1 >> h2;
		if (Y(h1) && Y(h2)) Q.push({ h1, h2});
		if (Vh(h1) && Y(h2)) ++VhY[h2];
		if (Y(h1) && Vh(h2)) ++VhY[h1];
	}
	pair<int, int> fr;
	while (!Q.empty())
	{
		fr = Q.front();
		while ((VhY[fr.first] < 0) || (VhY[fr.second] < 0))
		{
			if (VhY[fr.first] < 0) fr.first = -VhY[fr.first];
			if (VhY[fr.second] < 0) fr.second = -VhY[fr.second];
		}
		VhY[fr.first] = VhY[fr.first] + VhY[fr.second];
		VhY[fr.second] = -fr.first;
		Q.pop();
	}
	long long res{ 0 };
	for (int i = 2 * N + 1; i <= 2 * N + M; ++i)
		if (VhY[i] > 0)
			res += long long(VhY[i])*(VhY[i] - 1) / 2;

	fout << res;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}