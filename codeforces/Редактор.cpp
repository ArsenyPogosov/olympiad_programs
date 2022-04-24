//source: 
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
	int n; cin >> n;
	int i = 0, count = 0;
	vector<int> ps(n + 1), l(n * 2 + 2), r(n * 2 + 2);
	vector<char> str(n + 1);
	int lmin = 0, rmin = 0, lmax = 0, rmax = 0, add = 0;
	for (int t = 0; t < n; ++t)
	{
		char h; cin >> h;
		if (h == 'L' && i > 0)
		{
			++r[ps[i] - add + n];
			--l[ps[i] + n];
			rmax = max(rmax, ps[i] - add);
			rmin = min(rmin, ps[i] - add);
			if (!l[lmax + n])
				lmax = max(0, lmax - 1);
			if (!l[lmin + n])
				lmin = min(0, lmin + 1);
			ps[i] -= add;
			--i;
		}
		if (h == 'R')
		{
			--r[ps[i + 1] + n];
			++l[ps[i + 1] + add + n];
			lmax = max(lmax, ps[i + 1] + add);
			lmin = min(lmin, ps[i + 1] + add);
			if (!r[rmax + n])
				rmax = max(ps[i + 2], rmax - 1);
			if (!r[rmin + n])
				rmin = min(ps[i + 2], rmin + 1);
			ps[i] += add;
			++i;
		}
		if (h != 'L' && h != 'R')
		{
			--l[ps[i] + n];
			if (str[i] == '(') { --count; --add; --ps[i]; }
			if (str[i] == ')') { ++count; ++add; ++ps[i]; }
			str[i] = h;
			if (str[i] == '(') { ++count; ++add; ++ps[i]; }
			if (str[i] == ')') { --count; --add; --ps[i]; }
			++l[ps[i] + n];
		}
		if (count != 0 || lmin < 0 || rmin + add < 0)
			cout << -1 << '\n';
		else
			cout << max(lmax, rmax + add) << '\n';
	}

	return 0;
}