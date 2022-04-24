#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = (long long)(1e9);

long long n, N = (long long)(1e6) + 5;

long long count(pair<long long, long long> line, long long x) {
    return line.first * 1ll * x + line.second;
}

vector<pair<long long, long long>> tree(N * 4, {INF, INF});

void Add(long long v, long long l, long long r, pair<long long, long long> line) {
    if ((count(tree[v], l) <= count(line, l)) && (count(tree[v], r - 1) <= count(line, r - 1))) return;
    if ((count(tree[v], l) >= count(line, l)) && (count(tree[v], r - 1) >= count(line, r - 1))) {
        tree[v] = line;
        return;
    }

    long long m = (l + r) / 2;
    Add(v * 2 + 1, l, m, line);
    Add(v * 2 + 2, m, r, line);
}

void Add(pair<long long, long long> line) {
    Add(0, 0, N, line);
}

long long Query(long long v, long long l, long long r, long long x) {
    if (l + 1 == r) return count(tree[v], x);

    long long m = (l + r) / 2;
    if (x < m) return min(count(tree[v], x), Query(v * 2 + 1, l, m, x));
    return min(count(tree[v], x), Query(v * 2 + 2, m, r, x));
}

long long Query(long long x) {
    return Query(0, 0, N, x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<pair<long long, long long>> rect(n);

    for (auto& i : rect) cin >> i.first >> i.second;
    sort(rect.begin(), rect.end(), greater<pair<long long, long long>>());

    long long res = 0, mxwdth = -INF;
    for (auto& i : rect) {
        if (mxwdth >= i.second) continue;
        mxwdth = i.second;
        Add({ i.first, res });
        res = Query(i.second);
    }

    cout << res << '\n';

    return 0;
}
