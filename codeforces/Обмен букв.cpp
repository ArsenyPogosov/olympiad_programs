//source: https://codeforces.com/gym/102348/problem/G
//status: solved

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
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	list<int> af, bf;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 'a' && b[i] == 'b') af.push_back(i + 1);
		if (a[i] == 'b' && b[i] == 'a') bf.push_back(i + 1);
	}
	if ((af.size() + bf.size()) % 2 != 0)
		cout << -1;
	else
	{
		cout << (af.size() + bf.size()) / 2 + af.size() % 2 << '\n';
		while (af.size() > 1)
		{
			cout << af.front(); af.pop_front();
			cout << ' ' << af.front() << '\n'; af.pop_front();
		}
		while (bf.size() > 1)
		{
			cout << bf.front(); bf.pop_front();
			cout << ' ' << bf.front() << '\n'; bf.pop_front();
		}
		if (af.size())
		{
			cout << af.front() << ' ' << af.front() << '\n';
			cout << af.front() << ' ' << bf.front() << '\n';
		}
	}

	return 0;
}