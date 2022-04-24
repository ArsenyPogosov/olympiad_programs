#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(3));
	for (auto& i : a)
		for (auto& j : i)
			cin >> j;

	int m = 10;
	vector<int> f(m), s(m), l(m), ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i][0] > a[j][0]; });
	for (int i = 0; i < m; ++i) f[i] = ord[i];
	sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i][1] > a[j][1]; });
	for (int i = 0; i < m; ++i) s[i] = ord[i];
	sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i][2] > a[j][2]; });
	for (int i = 0; i < m; ++i) l[i] = ord[i];

	int mx = 0;
	vector<vector<int>> res(3);
	for (int f1 = 0; f1 < m; ++f1)
		for (int f2 = f1 + 1; f2 < m; ++f2)
			for (int f3 = f2 + 1; f3 < m; ++f3)
				for (int f4 = f3 + 1; f4 < m; ++f4)
					for (int f5 = f4 + 1; f5 < m; ++f5)
						for (int s1 = 0; s1 < m; ++s1)
							for (int s2 = s1 + 1; s2 < m; ++s2)
								for (int s3 = s2 + 1; s3 < m; ++s3)
									for (int l1 = 0; l1 < m; ++l1)
										for (int l2 = l1 + 1; l2 < m; ++l2)
										{
											set<int> ss{ f[f1],f[f2] ,f[f3] ,f[f4] ,f[f5], s[s1], s[s2], s[s3], l[l1], l[l2] };
											if (ss.size() != m)
												continue;

											int curr = a[f[f1]][0] + a[f[f2]][0] + a[f[f3]][0] + a[f[f4]][0] + a[f[f5]][0] + a[s[s1]][1] + a[s[s2]][1] + a[s[s3]][1] + a[l[l1]][2] + a[l[l2]][2];
											if (curr > mx)
											{
												mx = curr;
												res[0] = { f[f1],f[f2] ,f[f3] ,f[f4] ,f[f5] };
												res[1] = { s[s1], s[s2], s[s3] };
												res[2] = { l[l1], l[l2] };
											}
										}

	for (auto& i : res)
	{
		for (auto& j : i)
			cout << j + 1 << ' ';
		cout << '\n';
	}

	return 0;
}