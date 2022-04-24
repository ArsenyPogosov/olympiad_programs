#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long l{ 1 }, r{ n + 1 };
	bool SheIsHere{ false };
	
	string ans;
	while (!SheIsHere)
	{
		cout << (r + l) / 2 << '\n';
		cout.flush();
		ans = "";
		getline(cin, ans);
		if (ans == "")
			getline(cin, ans);
		if (ans == "Green beard")
			l = (r + l) / 2;
		if (ans == "A woman")
			r = (r + l) / 2;
		if (ans == "Mrs. Hudson is here")
			SheIsHere = true;
	}

	return 0;
}