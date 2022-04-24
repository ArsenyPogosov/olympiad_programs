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

const char f = 33;
const long long ALP = 126 - 33 + 1;
const long long base = 327, p = 454941, q = 67823;
//const long long base = 3, p = 1000000000, q = 1000000000;

int main()
{
	string s, fs; cin >> s >> fs;
	long long  n = s.size(), m = fs.size();
	vector<long long> bpowp(n + 10); bpowp[0] = 1;
	for (int i = 1; i < bpowp.size(); ++i) bpowp[i] = (bpowp[i - 1] * base) % p;
	vector<long long> bpowq(n + 10); bpowq[0] = 1;
	for (int i = 1; i < bpowq.size(); ++i) bpowq[i] = (bpowq[i - 1] * base) % q;
	vector<long long> bpowpsum(n + 10); bpowpsum[0] = 1;
	for (int i = 1; i < bpowpsum.size(); ++i) bpowpsum[i] = (bpowpsum[i - 1] + bpowp[i]) % p;
	vector<long long> bpowqsum(n + 10); bpowqsum[0] = 1;
	for (int i = 1; i < bpowqsum.size(); ++i) bpowqsum[i] = (bpowqsum[i - 1] + bpowq[i]) % q;
 	long long needp = 0, needq = 0;
	map<int, int> cc;
	for (int i = 0; i < m; ++i)
	{
		if (cc.find(fs[i] - f) == cc.end()) cc[fs[i] - f] = i + 1;
		needp = (needp + cc[fs[i] - f] * bpowp[i]) % p;
		needq = (needq + cc[fs[i] - f] * bpowq[i]) % q;
	}

	long long tp = 0, tq = 0;
	vector<long long> tbp(ALP), tbq(ALP);
	vector<list<long long>> cm(ALP);
	list<long long> ans;
	for (int i = 0; i < m; ++i)
	{
		int ch = s[i] - f;
		cm[ch].push_back(i + 1);
		tbp[ch] = (tbp[ch] + bpowp[i]) % p;
		tbq[ch] = (tbq[ch] + bpowq[i]) % q;
		tp = (tp + bpowp[i] * cm[ch].front()) % p;
		tq = (tq + bpowq[i] * cm[ch].front()) % q;
	}
	if ((tp == (needp * bpowp[0]) % p) && (tq == (needq * bpowq[0]) % q))
		ans.push_back(0);
	for (int i = 1; i <= n - m; ++i)
	{
		int ch = s[i - 1] - f;
		if (cm[ch].size() > 0)
		{
			tp = (tp - tbp[ch] * cm[ch].front() + p) % p;
			tq = (tq - tbq[ch] * cm[ch].front() + q) % q;
		}
		cm[ch].pop_front();
		tbp[ch] = (tbp[ch] - bpowp[i - 1] + p) % p;
		tbq[ch] = (tbq[ch] - bpowq[i - 1] + q) % q;
		if (cm[ch].size() > 0)
		{
			tp = (tp + tbp[ch] * cm[ch].front()) % p;
			tq = (tq + tbq[ch] * cm[ch].front()) % q;
		}

		ch = s[i + m - 1] - f;
		cm[ch].push_back(i + m);
		tbp[ch] = (tbp[ch] + bpowp[i + m - 1]) % p;
		tbq[ch] = (tbq[ch] + bpowq[i + m - 1]) % q;
		tp = (tp + bpowp[i + m - 1] * cm[ch].front()) % p;
		tq = (tq + bpowq[i + m - 1] * cm[ch].front()) % q;

		long long hp = (tp - (((bpowpsum[i + m - 1] - bpowpsum[i - 1] + p) % p) * i % p) + p) % p;
		long long hq = (tq - (((bpowqsum[i + m - 1] - bpowqsum[i - 1] + q) % q) * i % q) + q) % q;
		if ((hp == (needp * bpowp[i]) % p) && (hq == (needq * bpowq[i]) % q))
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) cout << i + 1 << ' ';

	return 0;
}