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

int n;
vector<int> fenv;

int sum(int it)
{
	int res = 0;
	while (it >= 0)
	{
		res += fenv[it];
		it = (it & (it + 1)) - 1;
	}
	return res;
}

void add(int it)
{
	while (it < n)
	{
		++fenv[it];
		it |= (it + 1);
	}
}

int main()
{
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) { cin >> i; --i; }
	vector<int> pos(n);
	for (int i = 0; i < n; ++i) pos[a[i]] = i;
	cout << 0 << ' ';
	int res = 0, l = pos[0], r = pos[0];
	fenv.resize(n);
	for (int k = 1; k < n; ++k)
	{
		if (l < pos[k] && pos[k] < r)
		{
			res += k - sum(pos[k]) * 2;
		}
		else
		{
			if (pos[k] < l)
			{
				res += ((l - pos[k] - 1) + (r - l + 1 - k)) + k;
				l = pos[k];
			}
			if (pos[k] > r)
			{
				res += pos[k] - r - 1;
				r = pos[k];
			}
			add(pos[k]);
		}
		cout << res << ' ';
	}

	return 0;
}