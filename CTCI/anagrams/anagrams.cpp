#include "stdafx.h"

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>

using namespace std;

const int alphabet_len = 26;

int number_needed(string a, string b) 
{
	std::array<int, alphabet_len> hgram = {0};
	long s = 0;
	for (char& c : a)
		++hgram[c - 'a'];
	for (char& c : b)
		--hgram[c - 'a'];
	for (int i=0; i<alphabet_len; ++i)
		s += std::abs(hgram[i]);

	return s;
}

int main() 
{
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	return 0;
}
