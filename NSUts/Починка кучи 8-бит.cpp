#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

ifstream fin("input.bin", std::ios_base::binary | std::ios_base::in);
ofstream fout("output.bin", std::ios_base::binary | std::ios_base::out);

char *s;

long long get(long long x)
{
	return (unsigned char)(s[x]);
}

void ct(unsigned long long a, unsigned long long b)
{
	fout.write((char*)(&a), 3);
	fout.write((char*)(&b), 1);
}

int main()
{
	fin.seekg(0, ios::end);
	long long n = fin.tellg();
	s = new char[n];
	fin.seekg(0, ios::beg);
	fin.read(s, n);
	fin.close();

	vector<char> res(n), psize(n);
	deque<list<int>> chng(260);
	set<pair<char, char>> bst;
	res[1] = (get(0) != 0) + (get(1) != 0); psize[1] = 2;
	bst.emplace(res[1], 1);
	chng[get(2)].push_back(1);
	for (int i = 2; i < n; ++i)
	{
		while (bst.begin()->second + 256 < i) bst.erase(bst.begin());
		int tbst = bst.begin()->second;
		res[i] = res[tbst] + 2;
		for (auto&j: chng[0])
			if (res[i] > res[j] + (i - j != get(i) + 2))
			{
				res[i] = res[j] + (i - j != get(i) + 2);
				tbst = j;
			}
		if (i <= 256)
			if (res[i] > 0 + (i - 1 != get(0)) + (get(i) != i - 1))
			{
				res[i] = 0 + (i - 1 != get(0)) + (get(i) != i - 1);
				tbst = -1;
			}

		psize[i] = i - tbst;
		bst.emplace(res[i], i);
		chng.pop_front();
		if (i + 1 < n)
			chng[get(i + 1)].push_back(i);
	}
	int tek = n - 1;
	while (tek != -1)
	{
		int ptek = tek - psize[tek] + 1;
		if (get(ptek) != psize[tek] - 2)
			ct(ptek, psize[tek] - 2);
		if (get(tek) != psize[tek] - 2)
			ct(tek, psize[tek] - 2);
		tek = ptek - 1;
	}

	return 0;
}