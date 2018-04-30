#include <iostream>

using namespace std;

int fibonacci_iter(int n)
{
	int i = 0;
	int a = 0;
	int b = 1;

	while (i < n)
	{
		int tmp = a;
		a = a + b;
		b = tmp;
		++i;
	}

	return a;
}

int fibonacci_recur(int n) {

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibonacci_recur(n - 2) + fibonacci_recur(n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << fibonacci_iter(n);
	return 0;
}
