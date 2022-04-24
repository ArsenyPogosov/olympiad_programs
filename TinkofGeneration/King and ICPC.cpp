#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, d;

int m = 17;
vector<vector<int>> a;
vector<vector<long long>> dst;

void buildDst(int l) {
    dst.assign(n, vector<long long>(d, -1));
    for (int i = (1 << l) - 1; i < n; i += (1 << l) * 2) {
        for (auto& k : a[i])
            dst[i][k % d] = max(dst[i][k % d], (long long)k);
        for (int j = i - 1; j > i - (1 << l); --j) {
            for (auto& k : a[j])
                for (int f = 0; f < d; ++f)
                    if (dst[j + 1][f] != -1)
                        dst[j][(k + f) % d] = max(dst[j][(k + f) % d], k + dst[j + 1][f]);
        }
    }
    for (int i = (1 << l); i < n; i += (1 << l) * 2) {
        for (auto& k : a[i])
            dst[i][k % d] = max(dst[i][k % d], (long long)k);
        for (int j = i + 1; j < i + (1 << l); ++j) {
            for (auto& k : a[j])
                for (int f = 0; f < d; ++f)
                    if (dst[j - 1][f] != -1)
                        dst[j][(k + f) % d] = max(dst[j][(k + f) % d], k + dst[j - 1][f]);
        }
    }
}

int loggg(int x) {
    int cnt = 0;
    for (; x > 0; x >>= 1, ++cnt) {}
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> d;
    a.resize(n);
    for (auto& i : a) {
        i.resize(3);
        cin >> i[0] >> i[1] >> i[2];
    }
    for (m = 0; (1 << m) < n; ++m) {}
    n = (1 << m);
    a.resize(n);

    int q; cin >> q;
    vector<vector<pair<int, pair<int, int>>>> query(m + 1);
    vector<long long> res(q, -1);
    buildDst(0);
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r; --l; --r;
        if (l == r) {
            res[i] = dst[l][0];
            continue;
        }
        int x = loggg(l ^ r) - 1;
        query[x].emplace_back(i, make_pair(l, r));
    }

    for (int i = 0; i <= m; ++i) {
        buildDst(i);
        for (auto& j : query[i]) {
            int l = j.second.first, r = j.second.second, id = j.first;
            for (int k = 0; k < d; ++k)
                if (dst[l][k] != -1 && dst[r][(d - k) % d] != -1)
                    res[id] = max(res[id], dst[l][k] + dst[r][(d - k) % d]);
        }
    }

    for (auto& i : res)
        cout << i << '\n';

    return 0;
}
