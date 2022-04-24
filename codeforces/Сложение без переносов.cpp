#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<string> A;

string solve12345(vector<string> a)
{
	for (auto& i : a) reverse(i.begin(), i.end());
	if (a[0].size() < a[1].size()) swap(a[0], a[1]);
	int l = a[0].size();
	int zzm = l;
	bool need = false;
	for (int i = l - 1; i >= 0; --i)
	{
		char s = '0';
		if (i < a[1].size()) s = a[1][i];
		if (s != a[0][i]) continue;
		if (s == '0') { zzm = i; continue; }
		need = true;
		for (int i = zzm - 1; i >= 0; --i)
		{
			char s = '0';
			if (i < a[1].size()) s = a[1][i];
			if (a[0][i] > s) break;
			if (a[0][i] < s) { swap(a[0], a[1]); break; }
		}
		for (int i = min(zzm, int(a[0].size())) - 1; i >= 0; --i)
			a[0][i] = '0';
		break;
	}
	if (!need) zzm = l + 5;
	string res = "";
	if (zzm == l)
		res += '1';
	for (int i = l - 1; i >= 0; --i)
	{
		if (i == zzm)
		{
			res += '1';
			continue;
		}
		if ((i < a[0].size()) && a[0][i] == '1')
		{
			res += '1';
			continue;
		}
		if ((i < a[1].size()) && a[1][i] == '1')
		{
			res += '1';
			continue;
		}
		res += '0';
	}
	return res;
}

void solve678()
{
	vector<bool> used(300001);
	set<int> canuse;
	for (int i = 0; i < 300001; ++i) canuse.insert(i);
	for (auto& i : A)
	{
		auto x = canuse.lower_bound(i.size() - 1);
		used[*x] = true;
		canuse.erase(x);
	}
	bool w0 = false;
	for (int i = 300000; i >= 0; --i)
	{
		if (used[i])
		{
			w0 = true;
			cout << 1;
		}
		else if (w0)
			cout << 0;
	}
	cout << '\n';
}

void solveind()
{
	string nw = A[0];
	for (int i = 1; i < n; ++i)
		nw = solve12345({ nw, A[i] });
	cout << nw << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	A.resize(n);
	for (auto& i : A) cin >> i;
	if (n == 2)
	{
		cout << solve12345(A) << '\n';
		return 0;
	}
	{
		bool is678 = false;
		for (auto& i : A)
		{
			for (int j = 1; j < i.size(); ++j)
				if (i[j] == '1')
				{
					is678 = false;
					break;
				}
			if (!is678) break;
		}
		if (is678)
		{
			solve678();
			return 0;
		}
	}
	sort(A.begin(), A.end(), [](string& a, string& b) {return a.size() < b.size(); });
	solveind();

	return 0;
}