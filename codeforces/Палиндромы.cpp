#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void count_sort(vector<int>& ind, vector<int>& val) {
    int n = ind.size(), m = *max_element(val.begin(), val.end()) + 1;
    vector<int> cnt(m), pos(m + 1);
    for (auto& i : val) ++cnt[i];
    partial_sum(cnt.begin(), cnt.end(), pos.begin() + 1);
    vector<int> res(n);
    for (auto& i : ind) res[pos[val[i]]++] = i;
    ind = res;
}

vector<int> par, rnk;
vector<pair<int, int>> cnt;

int get(int a) {
    if (par[a] == -1) return a;
    return par[a] = get(par[a]);
}

pair<int, int> unite(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return { -1, -1 };
    if (rnk[a] < rnk[b]) swap(a, b);
    par[b] = a;
    rnk[a] += rnk[b];
    cnt[a].first += cnt[b].first;
    cnt[a].second += cnt[b].second;

    return cnt[a];
}

pair<int, int> add(int a, pair<int, int> val) {
    a = get(a);
    cnt[a].first += val.first;
    cnt[a].second += val.second;

    return cnt[a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s; cin >> s; s += '$';
    int n = s.size();

    vector<int> sufmass(n), c(n); {
        iota(sufmass.begin(), sufmass.end(), 0);
        for (int i = 0; i < n - 1; ++i) c[i] = s[i] - 'a' + 1;
        count_sort(sufmass, c);
        vector<int> nc(n);
        int was = c[sufmass[0]];
        for (int i = 1; i < n; ++i) {
            int now = c[sufmass[i]];
            nc[sufmass[i]] = nc[sufmass[i - 1]] + (was != now);
            was = now;
        }
        c = nc;
    }
    for (int l = 2; l < n * 2; l <<= 1) {
        for (auto& i : sufmass) i = (n + i - l / 2) % n;
        count_sort(sufmass, c);
        vector<int> nc(n);
        pair<int, int> was = { c[sufmass[0]], c[(sufmass[0] + l / 2) % n] };
        for (int i = 1; i < n; ++i) {
            pair<int, int> now = { c[sufmass[i]], c[(sufmass[i] + l / 2) % n] };
            nc[sufmass[i]] = nc[sufmass[i - 1]] + (was != now);
            was = now;
        }
        c = nc;
    }

    vector<int> lcp(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        if (i > 0 && lcp[c[i - 1] - 1] > 0) lcp[c[i] - 1] = lcp[c[i - 1] - 1] - 1;
        for (; s[i + lcp[c[i] - 1]] == s[sufmass[c[i] - 1] + lcp[c[i] - 1]]; ++lcp[c[i] - 1]) {}
    }

    vector<vector<int>> ord(n + 1);
    for (int i = 0; i < n - 1; ++i)
        ord[lcp[i]].push_back(i);

    vector<int> olen(n, 1), elen(n);
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (i <= r) olen[i] = min(r - i + 1, olen[l + r - i]);
        for (; i - olen[i] >= 0 && i + olen[i] < n && s[i - olen[i]] == s[i + olen[i]]; ++olen[i]) {}
        if (i + olen[i] - 1 > r) {
            l = i - olen[i] + 1;
            r = i + olen[i] - 1;
        }
    }
    l = -1, r = -1;
    for (int i = 1; i < n; ++i) {
        if (i <= r) elen[i] = min(r - i + 1, elen[l + r - i + 1]);
        for (; i - elen[i] - 1 >= 0 && i + elen[i] < n && s[i - elen[i] - 1] == s[i + elen[i]]; ++elen[i]) { ; }
        if (i + elen[i] - 1 > r) {
            l = i - elen[i];
            r = i + elen[i] - 1;
        }
    }

    vector<vector<int>> oadd(n + 1), eadd(n + 1);
    for (int i = 0; i < n; ++i) {
        oadd[olen[sufmass[i]]].push_back(i);
        eadd[elen[sufmass[i]]].push_back(i);
    }

    long long res = 0;
    par.resize(n, -1); rnk.resize(n); cnt.resize(n);
    for (int i = n; i >= 0; --i) {
        for (auto& j : ord[i]) {
            auto h = unite(j, j + 1);
            res = max(res, (i * 2 - 1) * 1ll * h.first);
            res = max(res, (i * 2) * 1ll * h.second);
        }
        for (auto& j : oadd[i]) {
            auto h = add(j, {1, 0});
            res = max(res, (i * 2 - 1) * 1ll * h.first);
        }
        for (auto& j : eadd[i]) {
            auto h = add(j, {0, 1});
            res = max(res, (i * 2) * 1ll * h.second);
        }
    }

    cout << res << '\n';

    return 0;
}
