#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<int> a(n), ps(n);
	for (auto& i : a) cin >> i;
	partial_sum(a.begin(), a.end(), ps.begin(), [](int a, int b) { return a ^ b; });
	while (q--)
	{
		int a, b; cin >> a >> b; --a; --b;
		cout << (ps[b] ^ (a > 0 ? ps[a - 1] : 0)) << '\n';
	}

	return 0;
}