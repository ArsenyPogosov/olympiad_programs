#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int INF = int(1e9) + 228;

int nlg;
vector<int> lg2;

void buildlg2(int n) {
    ++n;
    nlg = n;
    lg2.resize(n + 1);
    for (int i = 0; (1 << i) <= n; ++i)
        fill(lg2.begin() + (1 << i), lg2.begin() + min((1 << (i + 1)), n + 1), i);
}

int n;
string s;

int m;
vector<vector<int>> MnST, MxST;

void buildMnST() {
    m = lg2[n] + 2;
    MnST.resize(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
        MnST[0][i] = (s[i] == '1' ? i : +INF);
    for (int i = 1; i < m; ++i)
        for (int j = 0; j < n; ++j)
            MnST[i][j] = min(MnST[i - 1][j], MnST[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

void buildMxST() {
    m = lg2[n] + 2;
    MxST.resize(m, vector<int>(n));
    for (int i = 0; i < n; ++i)
        MxST[0][i] = (s[i] == '0' ? i : -INF);
    for (int i = 1; i < m; ++i)
        for (int j = 0; j < n; ++j)
            MxST[i][j] = max(MxST[i - 1][j], MxST[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

int minLR(int l, int r) {
    int h = lg2[r - l + 1];
    return min(MnST[h][l], MnST[h][r - (1 << h) + 1]);
}

int maxLR(int l, int r) {
    int h = lg2[r - l + 1];
    return max(MxST[h][l], MxST[h][r - (1 << h) + 1]);
}

int resss(int a, int b) {
    return n / (a + b) * b + max(0, n % (a + b) - a);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();

    buildlg2(n);
    buildMnST();
    buildMxST();

    int aa = -1, ab = -1, res = -1;
    for (int i = 1; i <= n; ++i) {
        int a = 0, b = i;
        for (int j = 0; j < n; j += i) {
            int k = min(n - 1, j + i - 1);
            a = max(a, maxLR(j, k) - j);
            b = min(b, minLR(j, k) - j);
        }
        if (a >= b) continue;
        b = i - ++a;
        if (resss(a, b) > res) {
            res = resss(a, b);
            aa = a;
            ab = b;
        }
    }
    if (res == -1) {
        cout << -1;
    } else {
        for (int i = 0; i < n; ++i)
            cout << (i % (aa + ab) < aa ? '0' : '1');
    }
    cout << '\n';

    return 0;
}
