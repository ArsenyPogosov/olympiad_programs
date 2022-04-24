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
	int ttt; cin >> ttt;
	while (ttt--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		int maxx = a[0], minn = a[0], l = 0;
		bool flag = true;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] <= a[i - 1])
			{
				maxx = a[i];
				minn = a[i];
				l = i;
			}
			else
			{
				maxx = max(maxx, a[i]);
				minn = min(minn, a[i]);
			}
			if (maxx - minn >= i - l + 1)
			{
				cout << "YES\n" << l + 1 << ' ' << i + 1 << '\n';
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		reverse(a.begin(), a.end());
		maxx = a[0], minn = a[0], l = 0;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] <= a[i - 1])
			{
				maxx = a[i];
				minn = a[i];
				l = i;
			}
			else
			{
				maxx = max(maxx, a[i]);
				minn = min(minn, a[i]);
			}
			if (maxx - minn >= i - l + 1)
			{
				cout << "YES\n" << n - i << ' ' << n - l << '\n';
				flag = false;
				break;
			}
		}
		if (flag) cout << "NO\n";
	}

	return 0;
}