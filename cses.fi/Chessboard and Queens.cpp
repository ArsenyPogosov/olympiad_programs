#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<int>> board(8, vector<int>(8));

int res(int v)
{
	if (v >= 8) return 1;
	int count = 0;
	for (int i = 0; i < 8; ++i)
		if (!board[v][i])
		{
			auto wboard = board;
			for (int j = v + 1; j < 8; ++j)
				board[j][i] = true;
			for (int d = 1; d < 8; ++d)
			{
				if (v + d >= 8 || i - d < 0) break;
				board[v + d][i - d] = true;
			}
			for (int d = 1; d < 8; ++d)
			{
				if (v + d >= 8 || i + d >= 8) break;
				board[v + d][i + d] = true;
			}
			count += res(v + 1);
			board = wboard;
		}
	return count;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (auto&i: board)
		for (auto&j: i)
		{
			char h; cin >> h;
			j = h == '*';
		}
	cout << res(0) << '\n';

	return 0;
}