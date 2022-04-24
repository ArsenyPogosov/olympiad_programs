#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<string> elm{ "fake", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", };
unordered_map<string, int> revelm;

int n, k;
vector<int> a, b;
vector<vector<int>> good;
vector<int> masksum;

bool solve(int targ, int cantuse)
{
	if (targ == k)
	{
		cout << "YES\n";
		return true;
	}
	for (auto& mask : good[targ])
		if (!(mask & cantuse))
		{
			if (!solve(targ + 1, cantuse | mask)) continue;
			string res = "";
			for (int i = 0, wmask = mask; wmask > 0; ++i, wmask >>= 1)
				if (wmask % 2)
					res += elm[a[i]] + "+";
			res[res.size() - 1] = '-';
			cout << res << '>' << elm[b[targ]] << '\n';
			return true;
		}
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 101; ++i)
		revelm[elm[i]] = i;
	cin >> n >> k; a.resize(n); b.resize(k); good.resize(k); masksum.resize((1 << n));
	for (auto& i : a) { string h; cin >> h; i = revelm[h]; }
	for (auto& i : b) { string h; cin >> h; i = revelm[h]; }

	int h = 0;
	for (int mask = 1; mask < (1 << n); ++mask)
	{
		if (!(mask & (1 << h))) ++h;
		masksum[mask] = masksum[mask - (1 << h)] + a[h];
	}
	for (int i = 0; i < k; ++i)
		for (int mask = 0; mask < (1 << n); ++mask)
			if (masksum[mask] == b[i]) good[i].push_back(mask);
	if (!solve(0, 0))
		cout << "NO\n";

	return 0;
}