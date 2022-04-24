#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double k; cin >> k;

	cout << fixed << setprecision(2) << max(100.0, min(2000.0, 25 + k / 100)) << '\n';

	return 0;
}