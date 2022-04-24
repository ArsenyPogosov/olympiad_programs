#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool ask(int x1, int y1, int x2, int y2)
{
	cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
	bool res; cin >> res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<char>> res(n, vector<char>(n));

	res[0][0] = res[0][1] = 1;
	for (int j = 2; j < n; ++j)
		res[0][j] = res[0][j - 2] == ask(0, j - 2, 0, j);

	res[1][n - 2] = res[0][n - 3] == ask(0, n - 3, 1, n - 2);
	res[1][n - 1] = res[0][n - 2] == ask(0, n - 2, 1, n - 1);
	for (int j = n - 3; j >= 0; --j)
		res[1][j] = res[1][j + 2] == ask(1, j, 1, j + 2);

	for (int i = 2; i < n; ++i)
		for (int j = 0; j < n; ++j)
			res[i][j] = res[i - 2][j] == ask(i - 2, j, i, j);

	auto getd = [&](int d) {
		int i = min(d, n - 1), j = d - i;
		return res[i][j];
	};
	bool rev = false;
	for (int d = 0; d < n * 2 - 4; ++d)
	{
		if (getd(d) == getd(d + 3) && getd(d + 1) == getd(d + 2))
		{
			rev = !ask(min(d, n - 1), d - min(d, n - 1),
				min(d + 3, n - 1), d + 3 - min(d + 3, n - 1));
			break;
		}
		if (getd(d) != getd(d + 3) && getd(d + 1) != getd(d + 2))
		{
			rev = ask(min(d, n - 1), d - min(d, n - 1),
				min(d + 3, n - 1), d + 3 - min(d + 3, n - 1));
			break;
		}
	}
	if (rev)
		for (int i = 0; i < n; ++i)
			for (int j = 1 - i % 2; j < n; j += 2)
				res[i][j] ^= 1;

	cout << "!\n";
	for (auto& i : res)
	{
		for (auto& j : i)
			cout << int(j);
		cout << '\n';
	}
	cout << endl;

	return 0;
}