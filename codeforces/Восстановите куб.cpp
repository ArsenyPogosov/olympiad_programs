#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<int>> coord(8, vector<int>(3));

bool perp(vector<int> a, vector<int> b)
{
	return !(a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}
vector<int> Minus(vector<int> a, vector<int> b)
{
	a[0] -= b[0]; a[1] -= b[1]; a[2] -= b[2];
	return a;
}

int sqsize(vector<int> a)
{
	return a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
}

vector<int> sides(int v, int &l)
{
	int a = -1, b = -1;
	vector<int> result;
	for (int i = 0; i < 8; ++i)
	{
		if (i == v) continue;
		if (a = -1)
		{
			a = i;
			continue;
		}
		if (perp(Minus(coord[a], coord[v]), Minus(coord[i], coord[v])))
		{
			if (l == -1) l = sqsize(Minus(coord[a], coord[v]));
			if (l != sqsize(Minus(coord[i], coord[v]))) return { -1, -1, -1 };
			if (result.empty())
			{
				if (l != sqsize(Minus(coord[a], coord[v]))) return { -1, -1, -1 };
				b = -2;
				result.push_back(a);
			}
			result.push_back(i);
			if (result.size() > 3)
				return { -1, -1, -1 };
			continue;
		}
		if (b == -1)
		{
			b = i;
			continue;
		}
		a = b; b = -2; --i;
	}
	if (result.size() != 3)
		return { -1, -1, -1 };
	return result;
}

bool check()
{
	int l = -1;
	vector<int> s = sides(0, l);
	if (s[0] == -1) return false;
	vector<int> count(8);
	for (auto& i : s)
	{
		vector<int> h = sides(i, l);
		if (h[0] == -1) return false;
		if (!(h[0] * h[1] * h[2])) return false;
		for (auto& j : h) ++count[j];
	}
	int a = -1;
	vector<int> as;
	for (int i = 1; i < 8; ++i)
	{
		if (count[i] == 2)
			as.push_back(i);
		if (count[i] == 0)
			a = i;
	}
	if (a == -1) return false;
	if (as.size() != 3) return false;
	if (as != sides(a, l)) return false;
		
	return true;
}

bool iterate(int from = 0)
{
	if (from == 8) return check();

	do {
		if (iterate(from + 1))
			return true;
	} while (next_permutation(coord[from].begin(), coord[from].end()));
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (auto& i : coord)
	{
		for (auto& j : i)
			cin >> j;
		//sort(i.begin(), i.end());
	}
	if (iterate())
	{
		cout << "YES\n";
		for (auto& i : coord)
			for (auto& j : i)
				cout << j;
	}
	else
	{
		cout << "NO\n";
	}

	return 0;
}