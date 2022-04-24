#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 998244353;
const long long maxn = 1ll << (18 + 1);
const long long wn = 1847;
const long long wnneg = 510742238;
const long long div2 = (p + 1) / 2;

vector<long long> wnpow(maxn), wnnegpow(maxn);

int rev(int x, int k) {
    int res = 0;
    for (int i = 0; i < k; ++i)
        res |= ((x >> i) & 1) << (k - i - 1);
    return res;
}

void fft(vector<long long>& a, bool reg) {
    int n = a.size(), k = 1;
    for (; !((n >> k) & 1); ++k) {}

    for (int i = 0; i < n; ++i) {
        int j = rev(i, k);
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int l = 2; l <= n; l <<= 1)
        for (int i = 0; i < n; i += l)
            for (int j = 0; j < (l >> 1); ++j) {
                int x = i + j, y = i + j + (l >> 1);
                long long a0 = a[x], a1 = a[y], w;
                if (!reg)
                    w = wnpow[j * (maxn / l)];
                if (reg)
                    w = wnnegpow[j * (maxn / l)];
                a[x] = (a0 + w * a1) % p;
                a[y] = ((a0 - w * a1) % p + p) % p;
                if (reg) {
                    a[x] = (a[x] * div2) % p;
                    a[y] = (a[y] * div2) % p;
                }
            }
}

vector<long long> mult(vector<long long> a, vector<long long> b) {
    int n = 1;
    for (; n < max(a.size(), b.size()); n <<= 1) {} n <<= 1;
    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; ++i)
        a[i] = (a[i] * b[i]) % p;
    fft(a, true);

    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    wnpow[0] = 1;
    for (int i = 1; i < maxn; ++i) wnpow[i] = (wnpow[i - 1] * wn) % p;
    wnnegpow[0] = 1;
    for (int i = 1; i < maxn; ++i) wnnegpow[i] = (wnnegpow[i - 1] * wnneg) % p;

    int x; cin >> x;
    vector<long long> a(1 << x), b(1 << x);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    for (auto& i : mult(a, b))
        cout << i << ' ';

    return 0;
}
