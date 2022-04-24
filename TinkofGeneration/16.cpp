#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Vector {
    long double x, y;

    Vector(long double x = 0, long double y = 0): x(x), y(y) { }

    friend istream& operator>>(istream& in, Vector& a) {
        in >> a.x >> a.y;
        return in;
    }

    friend ostream& operator<<(ostream& out, Vector a) {
        out << a.x << ' ' << a.y;
        return out;
    }

    Vector operator+() { return *this; }
    Vector operator-() { return { -x, -y }; }

    Vector operator+(Vector b) {
        return { x + b.x, y + b.y };
    }
    Vector operator-(Vector b) {
        return { x - b.x, y - b.y };
    }
    Vector operator+=(Vector b) {
        x += b.x; y += b.y;
        return *this;
    }
    Vector operator-=(Vector b) {
        x -= b.x; y -= b.y;
        return *this;
    }

    Vector operator*(long double b)    {
        return { x * b, y * b };
    }
    Vector operator/(long double b)    {
        return { x / b, y / b };
    }
    Vector operator*=(long double b) {
        x *= b; y *= b;
        return *this;
    }
    Vector operator/=(long double b) {
        x /= b; y /= b;
        return *this;
    }

    long double operator*(Vector b)    {
        return x * b.x + y * b.y;
    }
    long double operator^(Vector b)    {
        return x * b.y - y * b.x;
    }

    long double sqlen()    {
        return x * x + y * y;
    }

    long double len() {
        return sqrt(sqlen());
    }
};

long double sqlen(Vector a) {
    return a.sqlen();
}

long double len(Vector a) {
    return a.len();
}

long double dpp(Vector a, Vector b) {
    return len(a - b);
}

long double dpr(Vector a, Vector b, Vector c) {
    if ((c - b) * (a - b) <= 0) return dpp(a, b);
    return (abs((a - b) ^ (c - b)) / len(c - b));
}

long double dps(Vector a, Vector b, Vector c) {
    return max(dpr(a, b, c), dpr(a, c, b));
}

long double dpl(Vector a, Vector b, Vector c) {
    return min(dpr(a, b, c), dpr(a, c, b));
}

long double dsp(Vector a, Vector b, Vector c) {
    return dps(c, a, b);
}

long double dsr(Vector a, Vector b, Vector c, Vector d) {
    if (((d - c) ^ (a - c)) * ((d - c) ^ (b - c)) < 0)
        if (((b - a) ^ (c - a)) * ((b - a) ^ (d - a)) < 0
            || dps(c, a, b) > dps(d, a, b))
            return 0;

    return min({ dpr(a, c, d), dpr(b, c, d), dps(c, a, b), dps(d, a, b) });
}

long double dss(Vector a, Vector b, Vector c, Vector d) {
    return max(dsr(a, b, c, d), dsr(a, b, d, c));
}

long double dsl(Vector a, Vector b, Vector c, Vector d) {
    return min(dsr(a, b, c, d), dsr(a, b, d, c));
}

long double drp(Vector a, Vector b, Vector c) {
    return dpr(c, a, b);
}

long double drs(Vector a, Vector b, Vector c, Vector d) {
    return dsr(c, d, a, b);
}

long double drr(Vector a, Vector b, Vector c, Vector d) {
    if (((d - c) ^ (a - c)) * ((d - c) ^ (b - c)) < 0 || dps(a, c, d) > dps(b, c, d))
        if (((b - a) ^ (c - a)) * ((b - a) ^ (d - a)) < 0 || dps(c, a, b) > dps(d, a, b))
            return 0;
    return min(dpr(a, c, d), dpr(c, a, b));
}

long double drl(Vector a, Vector b, Vector c, Vector d) {
    return min(drr(a, b, c, d), drr(a, b, d, c));
}

long double dlp(Vector a, Vector b, Vector c) {
    return dpl(c, a, b);
}

long double dls(Vector a, Vector b, Vector c, Vector d) {
    return dsl(c, d, a, b);
}

long double dlr(Vector a, Vector b, Vector c, Vector d) {
    return drl(c, d, a, b);
}

long double dll(Vector a, Vector b, Vector c, Vector d) {
    if (((a - b) ^ (c - d)) != 0) return 0;

    return min(drr(a, b, c, d), drr(a, b, d, c));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    Vector a, b, c, d; cin >> a >> b >> c >> d;

    cout << fixed << setprecision(16);
    cout << dpp(a, c) << '\n';
    cout << dps(a, c, d) << '\n';
    cout << dpr(a, c, d) << '\n';
    cout << dpl(a, c, d) << '\n';
    cout << dsp(a, b, c) << '\n';
    cout << dss(a, b, c, d) << '\n';
    cout << dsr(a, b, c, d) << '\n';
    cout << dsl(a, b, c, d) << '\n';
    cout << drp(a, b, c) << '\n';
    cout << drs(a, b, c, d) << '\n';
    cout << drr(a, b, c, d) << '\n';
    cout << drl(a, b, c, d) << '\n';
    cout << dlp(a, b, c) << '\n';
    cout << dls(a, b, c, d) << '\n';
    cout << dlr(a, b, c, d) << '\n';
    cout << dll(a, b, c, d) << '\n';

    return 0;
}
