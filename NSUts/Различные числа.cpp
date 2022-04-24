#include <fstream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <cmath>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<pair<int, int>> A(n);
	for (int i = 0; i <= n - 1; ++i)
	{
		fin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	list<pair<int, int>> NumToChange;
	for (int i = 0; i <= n - 2; ++i)
		if (A[i].first + 1 <= A[i + 1].first - 1)
			NumToChange.push_back({ A[i].first + 1, A[i + 1].first - 1 });
	if (A[n - 1].first + 1 <= 100000000)
		NumToChange.push_back({ A[n - 1].first + 1, 100000000 });
	vector<pair<int, int>> Answer;
	for (int i = 0; i <= n - 2; ++i)
		if (A[i].first == A[i + 1].first)
		{
			if (NumToChange.front().first > NumToChange.front().second)
				NumToChange.pop_front();
			Answer.push_back({ A[i].second, NumToChange.front().first });
			NumToChange.front().first += 1;
		}

	fout << Answer.size() << '\n';
	for (auto& i : Answer)
	{
		fout << (i.first + 1) << ' ' << i.second << '\n';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}