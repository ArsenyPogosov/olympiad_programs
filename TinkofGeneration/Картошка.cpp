#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m; cin >> n >> m;

    long long k;
    vector<long long> p;
    for (long long i = 2; i * 1ll * i <= m; ++i)
        if (m % i == 0)    {
            p.push_back(i);
            while (m % i == 0) m /= i;
        }
    if (m > 1)
        p.push_back(m);
    k = p.size();

    long long res = 0;
    for (long long mask = 0; mask < (1ll << k); ++mask) {
        long long mult = 1;
        long long count = 0;
        for (long long i = 0; i < k; ++i)
            if (mask & (1ll << i)) {
                mult *= p[i];
                ++count;
            }
        res += (count % 2 ? -1 : 1) * (n / mult);
    }
    cout << res << '\n';

    return 0;
}
