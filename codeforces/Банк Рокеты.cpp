//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258319/attachments/download/6442/statements.pdf
//status: coding

#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long res = 0, tek = (1 << 29);
	while (tek > 0)
	{
		cout << "TRANSFER " << tek << '\n';
		cout.flush();
		string s;
		cin >> s;
		if (s == "SUCCESS") res += tek;
		tek /= 2;
	}
	cout << "DONE " << res;
	cout.flush();

	return 0;
}