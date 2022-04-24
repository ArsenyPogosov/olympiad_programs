#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long mx = 25000;

long long get(long long x)
{
	cout << "read " << x << endl;
	long long res;
	cin >> res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;

	bool good = true;
	long long tek = 0;
	long long fi = -1, fv = -1, counter228 = 0;
	while (tek < n)
	{
		++counter228;
		if (counter228 > mx + 10)
		{
			good = false;
			break;
		}
		long long num = get(tek);
		long long ntek = tek + num + 2;
		if (ntek > n) { good = false; break; }
		long long num2 = get(ntek - 1);
		if (num2 != num)
		{
			if (fi != -1) { good = false; break; }
			fi = ntek - 1;
			fv = num;
		}
		tek = ntek;
	}
	if (good)
	{
		if (fi == -1)
		{
			cout << "fix 0" << endl;
		}
		else
		{
			cout << "fix 1" << endl << fi << ' ' << fv << endl;
		}
		return 0;
	}
	good = true;
	tek = n - 1;
	fi = -1;  fv = -1; counter228 = 0;
	while (tek >= 0)
	{
		++counter228;
		if (counter228 > mx + 10)
		{
			good = false;
			break;
		}
		long long num = get(tek);
		long long ntek = tek - num - 2;
		if (ntek < -1) { good = false; break; }
		long long num2 = get(ntek + 1);
		if (num2 != num)
		{
			if (fi != -1) { good = false; break; }
			fi = ntek + 1;
			fv = num;
		}
		tek = ntek;
	}
	if (good)
	{
		if (fi == -1)
		{
			cout << "fix 0" << endl;
		}
		else
		{
			cout << "fix 1" << endl << fi << ' ' << fv << endl;
		}
		return 0;
	}
	cout << "fix 2" << endl << 0 << ' ' << n - 2 << endl << n - 1 << ' ' << n - 2 << endl;

	return 0;
}