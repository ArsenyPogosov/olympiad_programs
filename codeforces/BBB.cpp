//source: http://neerc.ifmo.ru/school/sirius-2019/problems/20191111.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, c, ca = 0, cb = 0, cg = 0, best = 0, l = 0;
	cin >> n >> c;
	string s; cin >> s;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 'b') cg += ca;
		if (s[i] == 'a') ++ca;
		if (s[i] == 'b') ++cb;
		while (cg > c)
		{
			if (s[l] == 'a') cg -= cb;
			if (s[l] == 'a') --ca;
			if (s[l] == 'b') --cb;
			++l;
		}
		best = max(best, i - l + 1);
	}
	cout << best;

	return 0;
}