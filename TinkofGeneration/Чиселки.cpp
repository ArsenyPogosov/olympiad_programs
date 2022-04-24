#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = int(1e9) + 7;

int m;
vector<int> prime;
vector<int> minD;

void erat(int n) {
    minD.resize(n); minD[0] = minD[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!minD[i]) {
            minD[i] = i;
            prime.push_back(i);
        }
        for (auto& j : prime) {
            if (j > minD[i] || i * j >= n) break;
            minD[i * j] = j;
        }
    }
}

pair<int, int> GCD(int a, int b) {
    if (b == 0) return { 1, 0 };
    auto res = GCD(b, a % b);
    return { res.second, res.first - res.second * 1ll * (a / b) };
}

vector<int> fact, pfact;

int c(int n, int k) {
    return (((fact[n] * 1ll * pfact[k]) % p) * 1ll * pfact[n - k]) % p;
}

vector<vector<int>> dp;

int k;

int res(int x) {
    vector<int> a;
    while (x > 1) {
        int d = minD[x], cnt = 0;
        while (minD[x] == d) {
            x /= d;
            ++cnt;
        }
        a.push_back(cnt);
    }
    int n = a.size();

    int sz = 1, sum[130], cnt[130];
    sum[0] = cnt[0] = 0;
    for (int i = 0; i < n; ++i) {
        int tsz = sz;
        for (int j = 0; j < tsz; ++j) {
            sum[sz] = sum[j] + a[i] + 1;
            cnt[sz] = cnt[j] + 1;
            ++sz;
        }
    }
    long long ans = 0;
    for (int i = 0; i < sz; ++i) {
        if (sum[i] > k) continue;
        ans += (cnt[i] % 2 ? -1 : 1) * dp[k - sum[i]][n - cnt[i]];
    }

    return (ans % p + p) % p;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n >> k;

    erat(n + 1);
    for (int i = 2; i <= n; ++i)
        if (minD[i] == i)
            ++m;
    int h = k + m + 2;
    fact.resize(h); pfact.resize(h);
    fact[0] = pfact[0] = 1;
    for (int i = 1; i < h; ++i) {
        fact[i] = (fact[i - 1] * 1ll * i) % p;
        pfact[i] = ((pfact[i - 1] * 1ll * GCD(i, p).first) % p + p) % p;
    }

    h = min(8, m);
    dp.resize(k + 1, vector<int>(h + 1));
    for (int i = max(0, k - 30); i <= k; ++i) {
        vector<int> t(h + 1);
        for (int j = h; j >= 0; --j) {
            t[0] = c(i + m - j, m - j);
            for (int l = 1; l <= h - j; ++l)
                t[l] = ((t[l - 1] * 2 - dp[i][l - 1]) % p + p) % p;
            dp[i] = t;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + i * 1ll * res(i)) % p;

    cout << ans << '\n';

    return 0;
}
