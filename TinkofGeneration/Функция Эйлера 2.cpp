#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int cnt = 0;
int prime[1230], euler[int(1e8) + 1];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n = int(1e4), N = int(1e8);
    memset(euler, 0, sizeof euler); euler[1] = 1;
    int a = 2, b = n;
    for (int i = a; i <= b; ++i)
        if (!euler[i]) {
            euler[i] = i;
            prime[cnt++] = i;
            for (int j = i; j * i <= b; ++j)
                euler[i * j] = i;
        }
    for (int a = n + 1; a + n - 1 <= N; a += n)    {
        int b = a + n - 1;
        for (int k = 0; k < cnt; ++k) {
            int i = prime[k];
            for (int j = (a + i - 2) / i; j * i <= b; ++j)
                euler[i * j] = i;
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (!euler[i]) {
            euler[i] = i - 1;
        } else {
            int j = i / euler[i];
            euler[i] = euler[j] * (euler[i] - (j % euler[i] != 0));
        }
    }

    int qq = 16358801 - 100; cin >> n; b = n % 100; n -= b;
    for (int i = 1; i < min(n, qq); i += 100)
        cout << accumulate(euler + i, euler + i + 100, 0) << ' ';
    for (int i = qq; i < n; i += 100)
        cout << accumulate(euler + i, euler + i + 100, 0ll) << ' ';
    if (b)
        cout << accumulate(euler + n, euler + n + b + 1, 0ll) << ' ';
    cout << '\n';

    return 0;
}
