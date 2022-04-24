#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = int(1e8) + 7;

long long euler(long long n) {
    long long res = n;
    for (long long i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            res = res - res / i;
            while (n % i == 0) n /= i;
        }
    if (n > 1) res = res - res / n;

    return res;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long a, k; cin >> a >> k;
    k = (k + 1) / 2;
    while (k-- && a > 1)
        a = euler(a);
    cout << (a % p) << '\n';

    return 0;
}
