#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_map<int, int> X, Y;
	map<pair<int, int>, int> XY;
	vector<pair<int, int>> coord(n);
	for (auto& i : coord)
	{
		cin >> i.first >> i.second;
		++XY[i];
		++X[i.first];
		++Y[i.second];
	}
	long long count = 0;
	for (auto& i : X) count += (long long)(i.second) * (i.second - 1) / 2;
	for (auto& i : Y) count += (long long)(i.second) * (i.second - 1) / 2;
	for (auto& i : XY) count -= (long long)(i.second) * (i.second - 1) / 2;
	cout << count << '\n';

	return 0;
}