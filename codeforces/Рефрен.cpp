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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> s(n);
    for (auto& i : s) cin >> i;
    s.push_back(0); ++n; ++m;

    vector<int> sufmass(n), c(n); {
        iota(sufmass.begin(), sufmass.end(), 0);
        c = s;
        count_sort(sufmass, c);
        vector<int> nc(n);
        int was = c[sufmass[0]];
        for (int i = 1; i < n; ++i)    {
            int now = c[sufmass[i]];
            nc[sufmass[i]] = nc[sufmass[i - 1]] + (was != now);
            was = now;
        }
        c = nc;
    }
    for (int l = 2; l < n * 2 && c[sufmass[n - 1]] < n - 1; l <<= 1) {
        for (auto& i : sufmass) i = (n + i - l / 2) % n;
        count_sort(sufmass, c);
        vector<int> nc(n);
        pair<int, int> was = { c[sufmass[0]], c[(sufmass[0] + l / 2) % n] };
        for (int i = 1; i < n; ++i)    {
            pair<int, int> now = { c[sufmass[i]], c[(sufmass[i] + l / 2) % n] };
            nc[sufmass[i]] = nc[sufmass[i - 1]] + (was != now);
            was = now;
        }
        c = nc;
    }

    vector<int> lcp(n - 1);
    for (int i = 0; i < n - 1; ++i)    {
        if (i > 0 && lcp[c[i - 1] - 1] > 0) lcp[c[i] - 1] = lcp[c[i - 1] - 1] - 1;
        for (; s[i + lcp[c[i] - 1]] == s[sufmass[c[i] - 1] + lcp[c[i] - 1]]; ++lcp[c[i] - 1]) {}
    }

    vector<vector<int>> ord(n);
    for (int i = 0; i < n - 1; ++i)
        ord[lcp[i]].push_back(i);
    long long res = n - 1; int rlen = n - 1, rind = 0;
    vector<int> adjind(n);
    iota(adjind.begin(), adjind.end(), 0);
    for (int i = n - 1; i >= 0; --i) {
        for (auto& j : ord[i]) {
            int l = adjind[j], r = adjind[j + 1];
            adjind[l] = r; adjind[r] = l;
            if (res < (r - l + 1) * 1ll * i) {
                res = (r - l + 1) * 1ll * i;
                rlen = i;
                rind = sufmass[l];
            }
        }
    }

    cout << res << '\n' << rlen << '\n';
    for (int i = rind; i < rind + rlen; ++i)
        cout << s[i] << ' ';
    cout << '\n';

    return 0;
}
