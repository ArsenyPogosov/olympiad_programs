#include <fstream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
#include <stack>
//#include <string>
using namespace std;

vector<long long> numbers;
vector<long long> prostye;

list<long long> Dividors(long long n)
{
	if (n == 1) return list<long long>({});
	for (long long i = 0; i <= prostye.size() - 1; ++i)
		if (n % prostye[i] == 0)
		{
			long long newN = n;
			while (newN % prostye[i] == 0) newN = newN/ prostye[i];
			list<long long> ans = Dividors(newN);
			ans.push_back(prostye[i]);
			return ans;
		}

	return list<long long>({ n });
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	vector<bool> prost(31624, true);
	prost[0] = false;
	prost[1] = false;
	for (long long i = 2; i * i <= 31623; ++i)
		if (prost[i])
			for (long long j = i * i; j <= 31623; j += i)
				prost[j] = false;
	long long count = 0;
	for (long long i = 2; i <= 31623; ++i)
		if (prost[i]) ++count;
	prostye = vector<long long>(count);
	long long jjj = 0;
	for (long long i = 2; i <= 31623; ++i)
		if (prost[i]) prostye[jjj++] = i;

	long long n;
	fin >> n;
	numbers = vector<long long>(n);
	for (long long i = 0; i <= n - 1; ++i)
	{
		fin >> numbers[i];
		if (numbers[i] == 1)
		{
			fout << "Impossible";

			fin.close();  //close input file
			fout.close(); //close output file
			return 0;
		}
	}

	stack<pair<long long, list<long long>>> iter;
	iter.push(pair<long long, list<long long>>({ 0, list<long long>({}) }));
	list<long long> ans = list<long long>({ -1, -1, -1 });
	while (iter.size() != 0)
	{
		pair<long long, list<long long>> tekIter = iter.top();
		if (tekIter.first > n - 1) { ans = tekIter.second; break; }

		bool div = false;
		for (std::list<long long>::iterator it = tekIter.second.begin(); it != tekIter.second.end(); ++it)
		{
			if (numbers[tekIter.first] % (*it) == 0) div = true;
		}
		if (div)
		{
			iter.pop();
			++tekIter.first;
			iter.push(tekIter);

			continue;
		}

		if (tekIter.second.size() == 3)
		{
			iter.pop();
			continue;
		}

		list<long long> answer = Dividors(numbers[tekIter.first]);
		iter.pop();
		for (std::list<long long>::iterator it = answer.begin(); it != answer.end(); ++it)
		{
			pair<long long, list<long long>> toPush = tekIter;
			++toPush.first; toPush.second.push_back(*it);
			iter.push(toPush);
		}
	}

	if (ans == list<long long>({ -1, -1, -1 }))
		fout <<"Impossible";
	else
	{

		fout << "Possible\n";
		long long dev1 = 10000000000, dev2 = 10000000000, dev3 = 10000000000;
		dev1 = ans.front();
		ans.pop_front();
		if (ans.size() > 0)
		{
			dev2 = ans.front();
			ans.pop_front();
		}

		if (ans.size() > 0)
		{
			dev3 = ans.front();
			ans.pop_front();
		}

		for (long long i = 0; i <= n - 1; ++i)
		{
			if (numbers[i] % dev1 == 0)
			{
				fout << "1 ";
			}
			else
			{
				if (numbers[i] % dev2 == 0)
				{
					fout << "2 ";
				}
				else
				{
					fout << "3 ";
				}
			}

		}
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}