#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#include <algorithm>
#include <iostream>

const
int DEFAULT_MAX_LENGTH = 1000;                              // reserve vector (see belove) to this velue by the default

class BigInt {
private:
	// vector of numerals of the number
	std::vector<char> CharRepresentation;

	// the sign of the number
	char sign;
public:
	//														CONSTRUCTOR
	// constructor
	BigInt()
	{
		CharRepresentation.reserve(DEFAULT_MAX_LENGTH);
		CharRepresentation.push_back('0');
		sign = '+';
	}

	// constructor, value -- the value of the number
	BigInt(int value)
	{
		CharRepresentation.reserve(DEFAULT_MAX_LENGTH);
		sign = '+';
		if (value < 0) sign = '-';
		while (value != 0)
		{
			CharRepresentation.push_back(char('0' + std::max((value % 10), -(value % 10))));
			value = value / 10;
		}
	}

	// constructor, value -- the value of the number
	BigInt(const BigInt& value)
	{
		CharRepresentation.reserve(DEFAULT_MAX_LENGTH);
		CharRepresentation = value.CharRepresentation;
		sign = value.sign;
	}

	// constructor, MaxLength -- maximal length of number, value -- the value of the number
	BigInt(int value, int MaxLength)
	{
		CharRepresentation.reserve(MaxLength);
		sign = '+';
		if (value < 0) sign = '-';
		while (value != 0)
		{
			CharRepresentation.push_back(char('0' + std::max((value % 10), -(value % 10))));
			value = value / 10;
		}
	}

	// constructor, MaxLength -- maximal length of number, value -- the value of the number
	BigInt(const BigInt& value, int MaxLength)
	{
		CharRepresentation.reserve(MaxLength);
		CharRepresentation = value.CharRepresentation;
		sign = value.sign;
	}
	//														CONSTRUCTOR
	//														  CIN/COUT
	// cout << [BigInt]
	friend std::ostream& operator<<(std::ostream& os, const BigInt& bi)
	{
		if (bi.sign == '-') os << '-';
		for (int i = bi.CharRepresentation.size() - 1; i >= 0; --i)
			os << bi.CharRepresentation[i];

		return os;
	}

	// cin >> [BigInt]
	friend std::istream& operator >> (std::istream& is, BigInt& bi)
	{
		string aa;
		is >> aa;
		bi.sign = '+';
		int k{ 0 };
		if (aa[0] == '-') { ++k; bi.sign = '-'; };
		if (aa[0] == '+') { ++k; bi.sign = '+'; };
		bi.CharRepresentation.resize(aa.size() - k);
		for (int i = 0 + k; i <= aa.size() - 1; ++i)
			bi.CharRepresentation[aa.size() - i - 1] = aa[i];

		return is;
	}
	//														  CIN/COUT
	//													  [BigInt] -> int
	// from BigInt to int
	operator int()
	{
		int res{ 0 };
		for (int i = 0; i <= CharRepresentation.size() - 1; ++i)
			res += (CharRepresentation[i] - '0') * std::pow(10, i);
		if (sign == '-') res = -res;
		return res;
	}
	//													  [BigInt] -> int
	//														COMPARISION
	// [BigInt] < [BigInt]
	const bool operator<(const BigInt& b)
	{
		if (sign == '-' && b.sign == '+') return true;
		if (sign == '+' && b.sign == '-') return false;

		if (sign == '+' && b.sign == '+')
		{
			if (CharRepresentation.size() < b.CharRepresentation.size())
				return true;
			if (b.CharRepresentation.size() < CharRepresentation.size())
				return false;

			for (int i = CharRepresentation.size() - 1; i >= 0; --i)
			{
				if (CharRepresentation[i] < b.CharRepresentation[i])
					return true;
				if (b.CharRepresentation[i] < CharRepresentation[i])
					return false;
			}

			return false;
		}

		if (sign == '-' && b.sign == '-')
		{
			if (CharRepresentation.size() > b.CharRepresentation.size())
				return true;
			if (b.CharRepresentation.size() > CharRepresentation.size())
				return false;

			for (int i = CharRepresentation.size() - 1; i >= 0; --i)
			{
				if (CharRepresentation[i] > b.CharRepresentation[i])
					return true;
				if (b.CharRepresentation[i] > CharRepresentation[i])
					return false;
			}

			return false;
		}
	}

	// [BigInt] < [int]
	const bool operator<(int b)
	{
		BigInt bb(b);

		return (*this < bb);
	}

	// [BigInt] == [BigInt]
	const bool operator==(const BigInt& b)
	{
		if (CharRepresentation == b.CharRepresentation && sign == b.sign)
			return true;

		return false;
	}

	// [BigInt] == [int]
	const bool operator==(int b)
	{
		BigInt bb(b);

		return (*this == bb);
	}

	// [BigInt] > [BigInt]
	const bool operator>(const BigInt& b)
	{
		if (sign == '-' && b.sign == '+') return false;
		if (sign == '+' && b.sign == '-') return true;

		if (sign == '+' && b.sign == '+')
		{
			if (CharRepresentation.size() > b.CharRepresentation.size())
				return true;
			if (b.CharRepresentation.size() > CharRepresentation.size())
				return false;

			for (int i = CharRepresentation.size() - 1; i >= 0; --i)
			{
				if (CharRepresentation[i] > b.CharRepresentation[i])
					return true;
				if (b.CharRepresentation[i] > CharRepresentation[i])
					return false;
			}

			return false;
		}

		if (sign == '-' && b.sign == '-')
		{
			if (CharRepresentation.size() < b.CharRepresentation.size())
				return true;
			if (b.CharRepresentation.size() < CharRepresentation.size())
				return false;

			for (int i = CharRepresentation.size() - 1; i >= 0; --i)
			{
				if (CharRepresentation[i] < b.CharRepresentation[i])
					return true;
				if (b.CharRepresentation[i] < CharRepresentation[i])
					return false;
			}

			return false;
		}
	}

	// [BigInt] > [int]
	const bool operator>(int b)
	{
		BigInt bb(b);

		return (*this > bb);
	}
	//														COMPARISION
	//														   MODULE
	// module
	BigInt abs(BigInt b)
	{
		b.sign = '+';

		return b;
	}
	//														   MODULE
	//												   PLUS MINUS MULT. DIVID.
	// [BigInt] + [BigInt]
	BigInt operator+(const BigInt& b)
	{
		if (sign == '+' && b.sign == '+')
		{
			BigInt result1;
			int ai, bi, r{ 0 };
			result1.CharRepresentation.resize(0);
			for (int i = 0; i <= std::max(CharRepresentation.size(), b.CharRepresentation.size()) - 1; ++i)
			{
				if (i <= CharRepresentation.size() - 1) ai = int(CharRepresentation[i]) - int('0'); else ai = 0;
				if (i <= b.CharRepresentation.size() - 1) bi = int(b.CharRepresentation[i]) - int('0'); else bi = 0;
				result1.CharRepresentation.push_back(char((ai + bi + r) % 10 + int('0')));
				r = (ai + bi + r) / 10;
			}
			if (r != 0) result1.CharRepresentation.push_back(char(r + int('0')));
			result1.sign = '+';
			return result1;
		}
		if (sign == '-' && b.sign == '-')
		{
			BigInt result1;
			int ai, bi, r{ 0 };
			result1.CharRepresentation.resize(0);
			for (int i = 0; i <= std::max(CharRepresentation.size(), b.CharRepresentation.size()) - 1; ++i)
			{
				if (i <= CharRepresentation.size() - 1) ai = int(CharRepresentation[i]) - int('0'); else ai = 0;
				if (i <= b.CharRepresentation.size() - 1) bi = int(b.CharRepresentation[i]) - int('0'); else bi = 0;
				result1.CharRepresentation.push_back(char((ai + bi + r) % 10 + int('0')));
				r = (ai + bi + r) / 10;
			}
			if (r != 0) result1.CharRepresentation.push_back(char(r + int('0')));
			result1.sign = '-';
			return result1;
		}
		if (abs(*this) > abs(b))
		{
			BigInt result1;
			int ai, bi, r{ 0 };
			result1.CharRepresentation.resize(0);
			for (int i = 0; i <= std::max(CharRepresentation.size(), b.CharRepresentation.size()) - 1; ++i)
			{
				if (i <= CharRepresentation.size() - 1) ai = int(CharRepresentation[i]) - int('0'); else ai = 0;
				if (i <= b.CharRepresentation.size() - 1) bi = int(b.CharRepresentation[i]) - int('0'); else bi = 0;
				if (ai - bi - r >= 0)
				{
					result1.CharRepresentation.push_back(char(ai - bi - r + int('0')));
					r = 0;
				}
				else
				{
					result1.CharRepresentation.push_back(char(ai - bi - r + 10 + int('0')));
					r = 1;
				}
			}
			while (result1.CharRepresentation.back() == '0')
				result1.CharRepresentation.pop_back();
			result1.sign = sign;

			return result1;
		}
		BigInt result1;
		int ai, bi, r{ 0 };
		result1.CharRepresentation.resize(0);
		for (int i = 0; i <= std::max(CharRepresentation.size(), b.CharRepresentation.size()) - 1; ++i)
		{
			if (i <= CharRepresentation.size() - 1) ai = int(CharRepresentation[i]) - int('0'); else ai = 0;
			if (i <= b.CharRepresentation.size() - 1) bi = int(b.CharRepresentation[i]) - int('0'); else bi = 0;
			if (bi - ai - r >= 0)
			{
				result1.CharRepresentation.push_back(char(bi - ai - r + int('0')));
				r = 0;
			}
			else
			{
				result1.CharRepresentation.push_back(char(bi - ai - r + 10 + int('0')));
				r = 1;
			}
		}
		while (result1.CharRepresentation.back() == '0' && result1.CharRepresentation.size() > 1)
			result1.CharRepresentation.pop_back();
		result1.sign = b.sign;

		return result1;
	}

	// [BigInt] + [int]
	BigInt operator+(int b)
	{
		BigInt bb(b);

		return (*this + bb);
	}

	// [BigInt] - [BigInt]
	BigInt operator-(const BigInt& b)
	{
		BigInt bb(b);
		if (b.sign == '-') bb.sign = '+';
		else bb.sign = '-';

		return (*this + bb);
	}

	// [BigInt] - int
	BigInt operator-(int b)
	{
		BigInt bb(b);

		return (*this - bb);
	}

	// [BigInt] * [BigInt]
	BigInt operator*(const BigInt& b)
	{
		BigInt result1(0, CharRepresentation.size() + b.CharRepresentation.size() + 1);
		for (int i = 0; abs(BigInt(b)) > i; ++i)
			result1 = result1 + *this;

		return result1;
	}
	//												   PLUS MINUS MULT. DIVID.
};

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string word;
	fin >> word;
	int n{ int(word.size()) };
	vector<BigInt> dp(n);
	if (n <= 1)
	{
		fout << '1';

		fin.close();  //close input file
		fout.close(); //close output file

		return 0;
	}
	dp[n - 1] = 1;
	dp[n - 2] = 1;
	if ((word[n-2] != '0') && (int(word[n-2] - '0') * 10 + int(word[n-1] - '0') <= 33))
		dp[n-2] = dp[n-2] + 1;
	for (int i = n - 3; i >= 0; --i)
	{
		dp[i] = dp[i + 1];
		if ((word[i] != '0') && (int(word[i] - '0') * 10 + int(word[i + 1] - '0') <= 33))
			dp[i] = dp[i] + dp[i + 2];
	}

	fout << dp[0];

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}