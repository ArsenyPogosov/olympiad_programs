#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int euler[int(1e8) + 2];

void erat(int n) {
    memset(euler, -1, sizeof euler);
    euler[1] = 1;
    for (int i = 2; i * i < n; ++i)
        if (euler[i] == -1) {
            euler[i] = i;
            for (int j = i * 2; j < n; j += i)
                euler[j] = i;
        }
    for (int i = 2; i < n; ++i) {
        if (euler[i] == -1) euler[i] = i;
        int p = euler[i], ni = i / p;
        euler[i] = euler[ni] * (p - (ni % p != 0));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    erat(int(1e8) + 2);
    int n;  cin >> n;
    for (int i = 1; i < n; i += 100)
        cout << accumulate(euler + i, min(euler + i + 100, euler + n + 1), 0ll) << ' ';
    cout << '\n';

    return 0;
}
