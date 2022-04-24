//source: file:///C:/Users/arsen/Downloads/1%20(3).pdf
//status: solved

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

long long n;
string s;

long long claster(long long i)
{
	long long res = 1;
	while (i + res < n && s[i + res] == s[i]) ++res;
	return res;
}

int main()
{
	cin >> s;
	n = s.size();
	vector<vector<list<pair<long long, long long>>>> clasters('z' - 'a' + 1, vector<list<pair<long long, long long>>>('z' - 'a' + 1));
	vector<long long> maxClaster('z' - 'a' + 1);
	long long i = 0, cs1, cs2, cl1, cl2;
	cs1 = cs2 = cl1 = cl2 = -1;
	while (i < n)
	{
		cs1 = cs2; cl1 = cl2;
		cl2 = s[i] - 'a';
		cs2 = claster(i);
		i += cs2;
		maxClaster[cl2] = max(maxClaster[cl2], cs2);
		if (cs1 != -1)
			clasters[cl1][cl2].push_back({ cs1, cs2 });
	}
	long long res = 0;
	for (long long i = 0; i <= 'z' - 'a'; ++i)
	{
		res += maxClaster[i];
		for (long long j = 0; j <= 'z' - 'a'; ++j)
		{
			clasters[i][j].sort(greater<pair<long long, long long>>());
			long long maxy = -1, px = -1;
			auto& clast = clasters[i][j];
			while (clast.size())
			{
				if (px != -1 && clast.begin()->first != px)
				{
					res += (px - clast.begin()->first) * maxy;
				}
				px = clast.begin()->first;
				maxy = max(maxy, clast.begin()->second);
				clast.pop_front();
			}
			if (px > 0)
				res += px * maxy;
		}
	}
	cout << res;

	return 0;
}