#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const double pi = atan2(0, -1);

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long x, y; cin >> x >> y;
	long long a, b, c, d; cin >> a >> b >> c >> d;
	cout << fixed << setprecision(16) << a * atan(double(x) / y) / pi + b * atan(double(x) / y) / pi + c * atan(double(y) / x) / pi + d * atan(double(y) / x) / pi;

	return 0;
}