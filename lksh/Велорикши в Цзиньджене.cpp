#include <iostream>
#include <iomanip>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

const double INF = 1000000000000;

double dist(pair<double, double> a, pair<double, double> b)
{
	double dx = a.first - b.first, dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	vector<pair<double, double>> coord(2);
	vector<vector<double>> graph;
	cin >> coord[0].first >> coord[0].second >> coord[1].first >> coord[1].second;
	int n;
	cin >> n;
	coord.resize(n * 2 + 2);
	graph.resize(n * 2 + 2, vector<double>(n * 2 + 2, INF));
	for (int i = 2; i < n * 2 + 2; i += 2)
	{
		cin >> coord[i].first >> coord[i].second >> coord[i + 1].first >> coord[i + 1].second;
		cin >> graph[i][i + 1];
	}
	for (int i = 0; i < n * 2 + 2; ++i)
		for (int j = 0; j < n * 2 + 2; ++j)
			graph[i][j] = min(graph[i][j], dist(coord[i], coord[j]));
	vector<double> d(n * 2 + 2, INF);
	vector<bool> used(n * 2 + 2);
	d[0] = 0;
	for (int i = 0; i < n * 2 + 2; ++i)
	{
		int v = 0;
		for (int j = 0; j < n * 2 + 2; ++j)
			if (!used[j] && (d[j] < d[v] || used[v]))
				v = j;
		if (used[v])
			break;
		used[v] = true;
		for (int j = 0; j < n * 2 + 2; ++j)
			if (d[j] > d[v] + graph[v][j])
				d[j] = d[v] + graph[v][j];
	}
	cout << setprecision(20) << d[1];

	return 0;
}