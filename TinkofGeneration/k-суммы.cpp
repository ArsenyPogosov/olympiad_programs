#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

pair<long long, long long> GCD(long long a, long long b) {
    if (b == 0) return { 1, 0 };
    auto res = GCD(b, a % b);
    return { res.second, res.first - res.second * (a / b) };
}

long long LCM(int a, int b) {
    auto res = GCD(a, b);
    return a / (a * res.first + b * res.second) * b;
}

int n;

int solve(int k1, int k2) {
    // ak1 + 1 == bk2 => ak1 - bk2 = -1
    long long a = k1, b = -k2, c = -1;
    auto tttt = GCD(a, -b);
    long long t1 = tttt.first, t2 = -tttt.second, d = a * t1 + b * t2;
    if (c % d) {
        return 0;
    }
    a /= d; b /= d; c /= d; t1 *= c; t2 *= c;
    // 1 <= t2 * k2 <= n = > 1 <= t2 <= n/k2, t2 = t2 + ka => 1 - t2 <= ka <= n /k2 - t2=>
    long long down = (1 - t2) / a, up = (n / k2 - t2) / a;
    if (1 - t2 > 0 && (1 - t2) % a) ++down;
    if ((n / k2 - t2) < 0 && (n / k2 - t2) % a) --up;
    return max(0ll, up - down + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m; cin >> n >> m;
    vector<int> k(m);
    for (auto& i : k) cin >> i;
    ++m; k.push_back(n);

    for (auto& i : k)
        if (i == 1) {
            cout << n << '\n';
            return 0;
        }

    long long res = 0, mx = 1;
    for (int i = 0; i < m; ++i) mx *= 3;
    for (int mask = 1; mask < mx; ++mask) {
        long long hmask = mask, x = 0, a = 1, b = 1;
        for (int j = 0; j < m; ++j, hmask /= 3) {
            if (hmask % 3 == 1) {
                ++x;
                a = LCM(a, k[j]);
                if (a > n) break;
            }
            if (hmask % 3 == 2) {
                ++x;
                b = LCM(b, k[j]);
                if (b > n) break;
            }
        }
        if (a > n) continue;
        if (b > n) continue;
        if (a == 1 || b == 1) continue;

        res += (x % 2 ? -1 : 1) * solve(a, b);
    }
    cout << res << '\n';

    return 0;
}
