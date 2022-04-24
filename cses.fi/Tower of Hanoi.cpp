#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> step;

void solve(int n, int a, int b, int c)
{
	if (n == 0) return;

	solve(n - 1, a, c, b);
	step.emplace_back(a, c);
	solve(n - 1, b, a, c);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	solve(n, 1, 2, 3);
	
	cout << step.size() << '\n';
	for (auto& i : step)
		cout << i.first << ' ' << i.second << '\n';

	return 0;
}