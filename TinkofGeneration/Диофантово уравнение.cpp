#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

pair<long long, long long> GCD(long long a, long long b) {
    if (b == 0) return { 1, 0 };
    auto res = GCD(b, a % b);
    return { res.second, res.first - res.second * (a / b) };
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long a, b, c; cin >> a >> b >> c;
    auto tttt = GCD(a, b);
    long long t1 = tttt.first, t2 = tttt.second, d = a * t1 + b * t2;
    if (c % d) {
        cout << "Impossible\n";
        return 0;
    }
    a /= d; b /= d; c /= d; t1 *= c; t2 *= c;
    long long t = (t1) / b - (t1 < 0 && t1 % b);
    cout << t1 - t * b << ' ' << t2 + t * a << '\n';

    return 0;
}
