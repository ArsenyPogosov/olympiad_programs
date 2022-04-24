#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> t(n);
	for (auto& i : t) cin >> i;
	cout << accumulate(t.begin(), t.end(), 0ll) +
		max(0ll, *max_element(t.begin(), t.end()) * 2 - accumulate(t.begin(), t.end(), 0ll)) << '\n';

	return 0;
}