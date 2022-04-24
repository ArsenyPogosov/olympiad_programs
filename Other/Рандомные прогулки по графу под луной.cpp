#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> edge;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n = 500;
	for (int i = 0; i < n - 200; ++i)
		for (int j = i + 1; j < n - 200; ++j)
			edge.emplace_back(i + 1, j + 1);
	for (int i = n - 200 - 1; i < n - 1; ++i)
		edge.emplace_back(i + 1, i + 2);

	cout << n << ' ' << edge.size() << '\n';
	for (auto& i : edge)
		cout << i.first << ' ' << i.second << '\n';
	cout << "1 " << n << '\n';

	return 0;
}