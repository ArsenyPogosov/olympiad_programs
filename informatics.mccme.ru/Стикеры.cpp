#include <fstream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int sum{ 0 }, N, M, T;

vector<vector<int>> IminJ(9, vector<int>(9));

bool check(int x1, int x2, int y1, int y2, int i1, int i2, int j1, int j2)
{
	return (((x1 - y1)*IminJ[i1][j1] + (x2 - y2)*IminJ[i2][j2] + N) % N == (T - sum + N) % N);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	for (int i = 0; i <= 8; ++i)
		for (int j = 0; j <= 8; ++j)
			IminJ[i][j] = ((long long)pow(10, i) - (long long)pow(10, j)) % N;

	fin >> N >> M >> T;
	vector<vector<int>> TAB(9, vector<int>(10, -1));
	vector<list<int>> V(9);
	int h, tekR;
	for (int i = 1; i <= N; ++i)
	{
		fin >> h;

		sum = (sum + h) % M;
		tekR = 0;
		while (h > 0)
		{
			if (TAB[tekR][h % 10] == -1) V[tekR].push_back(h % 10);
			TAB[tekR][h % 10] = i;
			h /= 10;
			++tekR;
		}
	}

	bool flag = false;
	int i1, i2, j1, j2, x1, x2, y1, y2;
	for (i1 = 0; i1 <= 8 && !flag; ++i1)
	{
		for (i2 = 0; (i2 <= 8) && (!flag); ++i2)
		{
			for (j1 = 0; (j1 <= 8) && (!flag); ++j1)
			{
				for (j2 = 0; (j2 <= 8) && (!flag); ++j2)
				{
					for (auto& x1: V[i1])
					{
						for (auto& x2 : V[i2])
						{
							for (auto& y1 : V[j1])
							{
								for (auto& y2 : V[j2])
								{
									flag = check(x1, x2, y1, y2, i1, i2, j1, j2);								
								}
							}
						}
					}
				}
			}
		}
	}
	
	/*int res{0};
	if (!((x1 == y1) && (i1 == j1))) ++res;
	if (!((x2 == y2) && (i2 == j2))) ++res;
	fout << res << '\n';
	if (!((x1 == y1) && (i1 == j1))) fout << TAB[i1][x1] << ' ' << i1 << ' ' << TAB[j1][y1] << ' ' << j1;
	if (!((x1 == y1) && (i1 == j1))) fout << TAB[i2][x2] << ' ' << i2 << ' ' << TAB[j2][y2] << ' ' << j2;*/

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}