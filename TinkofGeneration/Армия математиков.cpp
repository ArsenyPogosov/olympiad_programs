#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = int(1e9) + 7;

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

void Devidors(vector<int> &res, int n) {
    res = vector<int>{ 1 };
    while (n > 1) {
        int sz = res.size();
        int tek = minD[n], ptek = 1;
        while (minD[n] == tek) {
            n /= tek;
            ptek *= tek;
            for (int i = 0; i < sz; ++i)
                res.push_back(res[i] * ptek);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    erat(int(1e6) + 10);
    vector<int> res(int(1e6) + 10), pow2(2*int(1e5) + 10);
    pow2[0] = 1;
    for (int i = 1; i < 2 * int(1e5) + 10; ++i) pow2[i] = (pow2[i - 1] * 2) % p;

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        vector<int> d; Devidors(d, a);
        for (auto& i : d)
            ++res[i];
    }
    for (auto& i : res)
        if (i) i = (pow2[i - 1] * 1ll * i) % p;
    int resss = 0;
    for (int i = int(1e6) + 10 - 1; i >= 2; --i)
        if (i) {
            for (int j = i * 2; j < int(1e6) + 10; j += i)
                res[i] = ((res[i] - res[j]) % p + p) % p;
            resss = (resss + res[i] * 1ll * i) % p;
        }
    cout << (resss % p) << '\n';

    return 0;
}
