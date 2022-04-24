//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("prizes.in");
ofstream fout("prizes.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n; cin >> n;
	int m1, m2 = -1; cin >> m1;
	for (int i = 1; i < n; ++i)
	{
		int m; cin >> m;
		m2 = max(m2, m);
		if (m1 < m2) swap(m1, m2);
		cout << m2 << ' ';
	}

	return 0;
}