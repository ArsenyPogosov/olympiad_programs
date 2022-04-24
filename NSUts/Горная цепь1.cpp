#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int h, n; cin >> h >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int w = accumulate(a.begin(), a.end(), 0) * 2;
	vector<vector<char>> res(h, vector<char>(w, '.'));
	for (int i = 0, w0 = 0; i < n; ++i)
	{
		for (int h0 = 1; h0 <= a[i]; ++h0, ++w0)
		{
			res[h - h0][w0] = '/';
			for (int k = 1; k < h0; ++k)
				res[h - k][w0] = '#';
		}
		for (int h0 = a[i]; h0 >= 1; --h0, ++w0)
		{
			res[h - h0][w0] = '\\';
			for (int k = 1; k < h0; ++k)
				res[h - k][w0] = '#';
		}
	}
	for (auto& i : res)
	{
		for (auto& j : i) cout << j;
		cout << '\n';
	}

	return 0;
}