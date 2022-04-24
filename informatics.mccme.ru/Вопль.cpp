#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int N, M, K;
	fin >> N >> M >> K;
	string alphabet;
	fin >> alphabet;
	vector<pair<string, int>> badWords(K);
	for (auto&i: badWords) fin >> i.first >> i.second;
	for (auto&i : badWords)
	{
		if (i.first.size() == 1) continue;
		for (auto&j : badWords)
			if (j.first == i.first[0] + "")
			{
				i.second += j.second;
				break;
			}
		for (auto&j : badWords)
			if (j.first == i.first[1] + "")
			{
				i.second += j.second;
				break;
			}
		if (i.first.size() == 2) continue;
		for (auto&j : badWords)
			if (j.first == i.first[2] + "")
			{
				i.second += j.second;
				break;
			}
		for (auto&j : badWords)
			if (j.first == i.first[0] + i.first[1] + "")
			{
				i.second += j.second;
				break;
			}
		for (auto&j : badWords)
			if (j.first == i.first[1] + i.first[2] + "")
			{
				i.second += j.second;
				break;
			}
	}
	
	vector<pair<int, string>> answer(N + 1, { 0, "" });
	for (int i = 1; i <= N; ++i)
	{
		answer[i] = { answer[i - 1].first, answer[i - 1].second + alphabet[0] };
		int newAns{ 0 };
		string lastString;
		for (auto&j : badWords)
		{
			if (i < j.first.size()) continue;

			newAns = j.second + answer[i - j.first.size()].first;
			lastString = answer[i - j.first.size()].second;
			if (lastString.size() >= 1)
				for (auto&k : badWords)
					if (k.first == lastString[lastString.size() - 1] + j.first[0] + "")
					{
						newAns += k.second;
						break;
					}

			if (lastString.size() >= 2)
				for (auto&k : badWords)
					if (k.first == lastString[lastString.size() - 2] + lastString[lastString.size() - 1] + j.first[0] + "")
					{
						newAns += k.second;
						break;
					}

			if ((lastString.size() >= 1)&&(j.first.size() >= 2))
				for (auto&k : badWords)
					if (k.first == lastString[lastString.size() - 1] + j.first[0] + j.first[1] + "")
					{
						newAns += k.second;
						break;
					}

			if (newAns > answer[i].first) answer[i] = { newAns, lastString + j.first };
		}
	}

	fout << answer[N].first << '\n' << answer[N].second;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}