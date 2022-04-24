#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> p(n);
	for (auto& i : p) cin >> i; sort(p.begin(), p.end());
	int j = n - 1;
	int count = 0;
	for (int i = 0; i <= j; ++i)
	{
		while (i < j && p[i] + p[j] > x) { --j; ++count; }
		++count;
		--j;
	}
	cout << count << '\n';

	return 0;
}