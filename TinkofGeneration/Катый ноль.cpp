#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a, fenv;

int get(int i) {
    int res = 0;
    while (i >= 0) {
        res += fenv[i];
        i = (i & (i + 1)) - 1;
    }

    return res;
}

int sumlr(int l, int r) {
    return get(r) - get(l - 1);
}

void change(int i, int v) {
    v = (v == 0);
    int add = -a[i] + v;
    a[i] = v;
    while (i < n) {
        fenv[i] += add;
        i |= (i + 1);
    }
}

int res(int l, int r, int k) {
    int L = l - 1, R = r + 1;
    while (L + 1 < R) {
        int m = (L + R) / 2;
        if (sumlr(l, m) < k)
            L = m;
        else
            R = m;
    }
    if (R <= r)
        return R + 1;
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n; a.resize(n); fenv.resize(n);
    for (int i = 0; i < n; ++i)    {
        int h; cin >> h;
        change(i, h);
    }

    int m; cin >> m;
    while (m--)    {
        char h; cin >> h;
        if (h == 's') {
            int a, b, c; cin >> a >> b >> c;
            cout << res(a - 1, b - 1, c) <<'\n';
        }
        if (h == 'u') {
            int a, b; cin >> a >> b;
            change(a - 1, b);
        }
    }

    return 0;
}
