//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int ttt; cin >> ttt;
	while (ttt--)
	{
		int n; cin >> n;
		vector<pair<int, pair<int, int>>> coord(n * 2);
		vector<pair<int, int>> seg(n);
		for (int i = 0; i < n; ++i)
		{
			int l, r; cin >> l >> r;
			coord[i * 2] = { l, {i, 0} };
			coord[i * 2 + 1] = { r, {i, 1} };
		}
		sort(coord.begin(), coord.end());
		int last = -1e9 - 1, tek = 0;
		for (auto& i : coord)
		{
			if (i.second.second == 0)
				seg[i.second.first].first = tek;
			else
				seg[i.second.first].second = tek;
			if (last != i.first)
			{
				last = i.first;
				++tek;
			}
		}
		++tek;
		vector<int> ev(tek + 1), c(tek);
		for (auto& i : seg)
		{
			++ev[i.first];
			--ev[i.second + 1];
		}
		int s = 0;
		for (int i = 0; i < tek; ++i)
		{
			s += ev[i];
			c[i] = s;
		}
		int now = 0;
		vector<pair<int, int>> b, m, a;
		int l = 0;
		while (l < tek)
		{
			while (l < tek && c[l] == 0) ++l;
			if (l >= tek) break;
			int r = l;
			while (r < tek && c[r] != 0) ++r;
			now += 1;
			l = r;
		}
		l = 0;
		while (l < tek)
		{
			while (l < tek && c[l] != 1) ++l;
			if (l >= tek) break;
			int r = l;
			while (r < tek && c[r] == 1) ++r;
			if ((l > 0 ? c[l - 1] : 0) == 0 && (r < tek - 1 ? c[r + 1] : 0) == 0)
			{
				a.push_back({ l, r });
			}
			else
			{
				if ((l > 0 ? c[l - 1] : 0) != 0 && (r < tek - 1 ? c[r + 1] : 0) != 0)
				{
					m.push_back({ l, r - 1});
				}
				else
				{
					b.push_back({ l, r - 1});
				}
			}
			l = r;
		}
		int best = -1;
		for (int i = 0; i < n; ++i)
		{
			int res = now;
			int cm = upper_bound(m.begin(), m.end(), pair<int, int>{ seg[i].second, tek + 1 }) - lower_bound(m.begin(), m.end(), pair<int, int>{seg[i].first, 0});
			res += cm;
			auto r = upper_bound(b.begin(), b.end(), pair<int, int>{ seg[i].second, tek + 1 });
			auto l = lower_bound(b.begin(), b.end(), pair<int, int>{seg[i].first, 0});
			int cb = r - l;
			if (cb == 1)
			{
				int rr = (*l).second, ll = (*l).first;
				if (ll == 0 || c[ll - 1] == 0)
				{
					if (ll < seg[i].first) ++res;
				}
				else
				{
					if (rr > seg[i].second) ++res;
				}
			}
			if (cb > 1)
			{
				if ((*l).first < seg[i].first) ++res;
				if ((*(--r)).second > seg[i].second) ++res;
			}
			r = upper_bound(a.begin(), a.end(), pair<int, int>{ seg[i].second, tek + 1 });
			l = lower_bound(a.begin(), a.end(), pair<int, int>{seg[i].first, 0});
			int ca = r - l;
			res -= ca;
			if (ca == 1)
			{
				if ((*l).first < seg[i].first || (*l).second > seg[i].second) ++res;
			}
			if (ca > 1)
			{
				if ((*l).first < seg[i].first) ++res;
				if ((*(--r)).second > seg[i].second) ++res;
			}
			best = max(best, tek);
		}
		cout << best << '\n';
	}

	return 0;
}