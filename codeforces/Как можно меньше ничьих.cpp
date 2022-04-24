#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> cnt(n, (n - 1) / 2), cnt0(n, 1 - n % 2);
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				if (cnt[i] > 0)
				{
					cout << "1 ";
					--cnt[i];
				}
				else
				{
					if (cnt0[i] > 0 && cnt0[j] > 0)
					{
						cout << "0 ";
						--cnt0[i];
						--cnt0[j];
					}
					else
					{
						cout << "-1 ";
						--cnt[j];
					}
				}
			}

		cout << '\n';
	}

	return 0;
}