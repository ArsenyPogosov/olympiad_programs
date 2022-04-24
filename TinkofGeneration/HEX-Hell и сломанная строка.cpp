#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// typedef complex<double> cmp;

const int MAXN = 2097152 / 100;

const int MAX_ALLOC = 268435456 - 14800000;
char MEM[MAX_ALLOC];
int t = 0;

void* operator new(size_t x) {
    t += x;
    return &MEM[t - x];
}

void operator delete(void* p) { }

struct cmp {
    float a; float b;
    cmp(float a = 0, float b = 0) : a(a), b(b) {}
    cmp operator+(cmp y) {
        return cmp(a + y.a, b + y.b);
    }
    cmp operator-(cmp y) {
        return cmp(a - y.a, b - y.b);
    }
    void operator+=(cmp y) {
        *this = *this + y;
    }
    void operator-=(cmp y) {
        *this = *this - y;
    }
    cmp operator*(cmp y) {
        return cmp(a * y.a - b * y.b, a * y.b + b * y.a);
    }
    cmp operator/(int n) {
        return cmp(a/ n, b/ n);
    }
    void operator*=(cmp n) {
        *this = *this * n;
    }
    void operator/=(int n) {
        *this = *this / n;
    }
};

cmp makecmp(double r, double phi) {
    return cmp(r * cos(phi), r * sin(phi));
}

int rrr[MAXN];
int reverse(int x, int k) {
    int res = 0;
    for (int i = 0; i < k; ++i)
        res |= (((x >> i) & 1) << (k - i - 1));

    return res;
}

cmp wpow[MAXN / 2];
void fft(cmp * a, int n, bool rev = false) {
    for (int i = 0; i < n; ++i) {
        int j = rrr[i];
        if (i < j) swap(a[i], a[j]);
    }

    cmp w = makecmp(1, 2 * atan2(0, -1) / n * (rev ? -1 : 1));
    wpow[0] = 1;
    for (int i = 1; i < n / 2; ++i) wpow[i] = wpow[i - 1] * w;

    for (int l = 2, ppp = 1; l <= n; l <<= 1, ++ppp) {
        for (int i = 0; i < n; i += l)
            for (int j = 0; j < l / 2; ++j) {
                cmp x = a[i + j], y = a[i + j + l / 2] * wpow[j * (n / l)];
                a[i + j] = x + y;
                a[i + j + l / 2] = x - y;
            }
    }

    if (rev)
        for (int i = 0; i < n; ++i) a[i] /= n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string alp['F' + 1 - '0'];
    alp['0' - '0'] = "0000";
    alp['1' - '0'] = "0001";
    alp['2' - '0'] = "0010";
    alp['3' - '0'] = "0011";
    alp['4' - '0'] = "0100";
    alp['5' - '0'] = "0101";
    alp['6' - '0'] = "0110";
    alp['7' - '0'] = "0111";
    alp['8' - '0'] = "1000";
    alp['9' - '0'] = "1001";
    alp['A' - '0'] = "1010";
    alp['B' - '0'] = "1011";
    alp['C' - '0'] = "1100";
    alp['D' - '0'] = "1101";
    alp['E' - '0'] = "1110";
    alp['F' - '0'] = "1111";

    string sa, sb;
    cin >> sa >> sb;

    int n = sa.size() * 4, m = sb.size();
    int N = 1, k = 0;
    for (; N < (n + m); N <<= 1, ++k) {} N <<= 1, ++k;

    for (int i = 0; i < N; ++i)
        rrr[i] = reverse(i, k);

    /* wpow.resize(k + 1);
    for (int i = 1; i <= k; ++i) {
        cmp w = makecmp(1, 2 * atan2(0, -1) / (1 << i));
        wpow[i].resize(max(1, (1 << i) / 2));
        wpow[i][0] = 1;
        for (int j = 1; j < (1 << i) / 2; ++j) wpow[i][j] = wpow[i][j - 1] * w;
    } */

    cmp a1[MAXN], a2[MAXN], b[MAXN];
    for (int i = 0; i < sa.size(); ++i)
        for (int j = 0; j < 4; ++j) {
            a1[i * 4 + j] = cmp(alp[sa[i] - '0'][j] - '0', 0);
            a2[i * 4 + j] = cmp('1' - alp[sa[i] - '0'][j], 0);
        }
    reverse(sb.begin(), sb.end());
    for (int i = 0; i < sb.size(); ++i) {
        if (sb[i] != '?') {
            b[i] = cmp(sb[i] - '0', 0);
        } else {
            b[i] = cmp(1, 0);
        }
    }

    fft(a1, N, false); fft(a2, N, false);
    fft(b, N, false);

    for (int i = 0; i < N; ++i) a1[i] *= b[i];

    fill(b, b + N, cmp(0, 0));
    for (int i = 0; i < sb.size(); ++i) {
        if (sb[i] != '?') {
            b[i] = cmp('1' - sb[i], 0);
        } else {
            b[i] = cmp(1, 0);
        }
    }

    fft(b, false);

    for (int i = 0; i < N; ++i) a1[i] += a2[i] * b[i];

    /* wpow.resize(k + 1, vector<cmp>(N / 2));
    for (int i = 1; i <= k; ++i) {
        cmp w = makecmp(1, - 2 * atan2(0, -1) / (1 << i));
        wpow[i][0] = 1;
        for (int j = 1; j < (1 << i) / 2; ++j) wpow[i][j] = wpow[i][j - 1] * w;
    } */
    fft(a1, N, true);

    for (int i = 0; i + m - 1 < n; i += 8)
        cout << (int)(a1[i + m - 1].a + 0.4) << ' ';
    cout << '\n';

    return 0;
}
