#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef complex<double> comp;

comp makecomp(double r, double fi)
{
	return comp(r * cos(fi), r * sin(fi));
}

int rev(int n, int k)
{
	int res = 0;
	for (int i = 0; i < k; ++i)
		res |= ((n >> i) & 1) << (k - i - 1);

	return res;
}

void fft(vector<comp>& a, bool rv)
{
	int n = a.size(), k;
	for (k = 0; !((n >> k) & 1); ++k);

	for (int i = 0; i < n; ++i)
	{
		int j = rev(i, k);
		if (i < j)
			swap(a[i], a[j]);
	}

	vector<comp> wpow(n >> 1); wpow[0] = comp(1);
	for (int l = 2; l <= n; l <<= 1)
	{
		comp w = makecomp(1, 2 * atan2(0, -1) / l * (rv ? -1 : 1));
		for (int i = 1; i < (l >> 1); ++i) wpow[i] = wpow[i - 1] * w;
		for (int i = 0; i < n; i += l)
			for (int j = 0; j < (l >> 1); ++j)
			{
				int x = i + j, y = i + j + l / 2;
				comp a0 = a[x], a1 = a[y];
				a[x] = a0 + wpow[j] * a1;
				a[y] = a0 - wpow[j] * a1;
			}
	}
	if (rv)
		for (auto& i : a) i /= n;
}

vector<int> mult(vector<int> a, vector<int> b)
{
	vector<comp> ca(a.begin(), a.end()), cb(b.begin(), b.end());
	int n = 1;
	for (n = 1; n < max(ca.size(), cb.size()); n <<= 1);
	n <<= 1;
	ca.resize(n);
	cb.resize(n);

	fft(ca, false);
	fft(cb, false);
	for (int i = 0; i < n; ++i)
		ca[i] *= cb[i];
	fft(ca, true);

	vector<int> res(n);
	for (int i = 0; i < n; ++i)
		res[i] = int(ca[i].real() + 0.5);
	return res;
}

string mult(string &a, string &b)
{
	vector<int> va, vb, vres;
	bool neg = ((a[0] == '-') ^ (b[0] == '-'));
	for (int i = a.size() - 1; i >= (a[0] == '-'); --i)
		va.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= (b[0] == '-'); --i)
		vb.push_back(b[i] - '0');

	vres = mult(va, vb);
	for (int i = 0; i < vres.size() - 1; ++i)
	{
		vres[i + 1] += vres[i] / 10;
		vres[i] %= 10;
	}

	string res = (neg ? "-" : "");
	int i = vres.size() - 1;
	for (; i >= 0 && !vres[i]; --i);
	if (i < 0) return "0";
	for (; i >= 0; --i)
		res += '0' + vres[i];

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;
	cout << mult(a, b) << '\n';

	return 0;
}