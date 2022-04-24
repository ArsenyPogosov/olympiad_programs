#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime;
vector<int> minD, euler;

void erat(int n) {
    minD.resize(n); minD[0] = minD[1] = 1;
    euler.resize(n); euler[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!minD[i]) {
            minD[i] = i;
            prime.push_back(i);
        }
        for (auto& j : prime) {
            if (j > minD[i] || i * j >= n) break;
            minD[i * j] = j;
        }
        int p = minD[i], ni = i / p;
        euler[i] = euler[ni] * (p - (minD[ni] != p));
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    erat(int(1e8) + 2);
    int n;  cin >> n;
    for (int i = 1; i < n; i += 100)
        cout << accumulate(euler.begin() + i, min(euler.begin() + i + 100, euler.begin() + n + 1), 0ll) << ' ';
    cout << '\n';

    return 0;
}