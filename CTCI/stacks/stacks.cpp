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

using namespace std;

bool is_open(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return true;
	return false;
}

bool is_closed(char c)
{
	if (c == ')' || c == ']' || c == '}')
		return true;
	return false;
}

char opp(char c)
{
	switch (c)
	{
	case '(': return ')'; break;
	case '[': return ']'; break;
	case '{': return '}'; break;
	case ')': return '('; break;
	case ']': return '['; break;
	case '}': return '{'; break; 
	default: return '\0';
	}

	return '\0';
}


bool match(std::stack<char>& br, char& c)
{
	if (br.empty())
		return false;

	if (br.top() == opp(c))
	{
		return true;
	}
	else
		return false;
}


bool is_balanced(string expression)
{
	std::stack<char> brackets;
	
	for (char c : expression)
	{
		if (is_open(c))
			brackets.push(c);
		else if (is_closed(c))
		{
			if (!match(brackets, c))
				return false;

			brackets.pop();
		}
	}

	if (brackets.empty())
		return true;
	else
		return false;
}

int main() 
{
	int t;
	cin >> t;

	for (int a0 = 0; a0 < t; a0++) {
		string expression;
		cin >> expression;
		bool answer = is_balanced(expression);
		if (answer)
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
