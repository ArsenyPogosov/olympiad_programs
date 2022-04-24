#include<bits/stdc++.h>
using namespace std;

int c1 = 123238, c3 = 23;

int main()
{
	string reg; cin >> reg;
	vector<int> l(1000, -1), r(10000, -1);

	for (int i = 0; i < 10; ++i)
		for (int j = i + 1; j < 10; ++j)
			for (int k = j + 1; k < 10; ++k)
			{
				for (int d = 0; d < 10; ++d)
				{
					if (i == d || j == d || k == d) continue;
					vector<int> tek{ i, j, k, d };
					sort(tek.begin(), tek.end());

					int sum = tek[0] * 1 + tek[1] * 10 + tek[2] * 100 + tek[3] * 1000;
					if (r[sum] != -1) continue;

					l[i * 1 + j * 10 + k * 100] = r[sum] = d;
					break;
				}
			}

	if (reg == "add")
	{
		int t; cin >> t;
		while (t--)
		{
			int n, k; cin >> n >> k;
			vector<int> a(k);
			for (auto& i : a) cin >> i;
			sort(a.begin(), a.end());

			if (n == 1000000)
			{
				cout << c1 << '\n';
			}

			if (n == 10)
			{
				cout << l[a[0] * 1 + a[1] * 10 + a[2] * 100 - 1 - 10 - 100] + 1 << '\n';
			}

			if (n == 100000)
			{
				vector<int> cnt(100000 + 1);
				for (auto& i : a) ++cnt[i];

				int targ;
				for (int i = 1; i <= 100000; ++i)
				{
					int sum = 0;
					for (int j = i; j < i + c3; ++i)
						sum += cnt[j];
					if (!sum) continue;

					targ = i;
					break;
				}
				cout << targ << '\n';
			}
		}
	}

	if (reg == "clear")
	{
		int t; cin >> t;
		while (t--)
		{
			int n, k; cin >> n >> k;
			vector<int> a(k + 1);
			for (auto& i : a) cin >> i;
			sort(a.begin(), a.end());

			if (n == 1000000)
			{
				for (auto& i : a)
					if (i != c1)
						cout << i << ' ';

				cout << '\n';
			}

			if (n == 10)
			{
				int imposter = r[a[0] * 1 + a[1] * 10 + a[2] * 100 + a[3] * 1000 - 1 - 10 - 100 - 1000] + 1;
				for (auto&i: a)
					if (i != imposter)
						cout << i << ' ';
				cout << '\n';
			}

			if (n == 100000)
			{
				vector<int> cnt(100000 + 1);
				for (auto& i : a) ++cnt[i];

				int targ;
				for (int i = 1; i <= 100000; ++i)
				{
					if (cnt[i] != 1) continue;
					int sum = 0;
					for (int j = i + 1; j < i + c3; ++i)
						sum += cnt[j];
					if (sum) continue;

					targ = i;
					break;
				}

				for (auto& i : a)
					if (i != targ)
						cout << i << ' ';
				cout << '\n';
			}
		}

	}

	return 0;
}