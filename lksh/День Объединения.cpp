//It's not a copy of another submittion
#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const double INF = 100000000000000000;

vector<bool> used;
vector<double> dist;
vector<pair<long long, long long>> cor;

double len(int i, int j)
{
	int dx = cor[i].first - cor[j].first;
	int dy = cor[i].second - cor[j].second;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	long long n;
	cin >> n;
	cor.resize(n);
	for (auto&i : cor)
		cin >> i.first >> i.second;
	used.resize(n, false);
	dist.resize(n, INF);
	dist[0] = 0;
	double sum = 0;
	while (true)
	{
		int v = -1;
		for (int i = 0; i < n; ++i)
			if ((v == -1 || dist[i] < dist[v]) && !used[i])
				v = i;
		if (v == -1)
			break;
		used[v] = true;
		sum += dist[v];

		for (int i = 0; i < n; ++i)
			if (!used[i])
				if (dist[i] > len(i, v))
					dist[i] = len(i, v);
	}
	cout << setprecision(20) << sum;

	return 0;
}