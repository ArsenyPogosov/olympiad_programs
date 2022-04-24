#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int mc = int(1e3);

vector<int> x{ -mc - 1, -mc - 1, mc + 1, mc + 1 };
vector<int> y{ -mc - 1, mc + 1, mc + 1, -mc - 1 };
vector<int> vx1{1, 1, -1, -1};
vector<int> vy1{0, 0, 0, 0};
vector<int> vx2{0, 0, 0, 0};
vector<int> vy2{1, -1, -1, 1};

int p1 = 0, p2 = 1;
double cos1, cos2;

double tcos(int x1, int y1, int x2, int y2)
{
	return double(x1 * x2 + y1 * y2) / sqrt(x1 * x1 + y1 * y1) / sqrt(x2 * x2 + y2 * y2);
}

double ask(int x, int y, int vx, int vy)
{
	cout << "? " << x << ' ' << y << ' ' << vx << ' ' << vy << endl;
	double res; cin >> res;
	return res;
}

bool find(int& p, double& cos)
{
	double cs = ask(x[p], y[p], vx1[p], vy1[p]);
	if (cs == -1)
		return true;
	if (cs == 0)
	{
		p = (p + 2) % 4;
		find(p, cos);
		return false;
	}
	double sn = ask(x[p], y[p], vx2[p], vy2[p]);
	if (sn == -1)
		return true;
	if (sn == 0)
	{
		p = (p + 2) % 4;
		find(p, cos);
		return false;
	}
	double k = sqrt(cs * cs + sn * sn);
	cos = cs / k;
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	if (find(p1, cos1)) return 0;
	if (find(p2, cos2)) return 0;

	int xbest = -1, ybest = -1;
	double resbest = 2281337;

	for (int tx = -mc; tx <= mc; ++tx)
		for (int ty = -mc; ty <= mc; ++ty)
		{
			double tcos1 = tcos(vx1[p1], vy1[p1], tx - x[p1], ty - y[p1]),
				tcos2 = tcos(vx1[p2], vy1[p2], tx - x[p2], ty - y[p2]);
			double res = abs(tcos1 - cos1) + abs(tcos2 - cos2);
			if (res < resbest)
			{
				resbest = res;
				xbest = tx;
				ybest = ty;
			}
		}

	ask(xbest, ybest, 0, 1);

	return 0;
}