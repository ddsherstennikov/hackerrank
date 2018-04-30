#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



vector<long> f_stored(33, -1);



long f(int steps)
{
	if (f_stored[steps] != -1)
		return f_stored[steps];
	else
	{
		f_stored[steps] = f(steps - 1) + f(steps - 2) + f(steps - 3);
		return f_stored[steps];
	}
}



int main() 
{
	
	f_stored.insert(f_stored.begin(), { 0, 1, 2 , 4 });

	int n;
	cin >> n;

	vector<int> stairs(n);
	for (int i = 0; i < n; ++i)
		cin >> stairs[i];

	for (int i = 0; i < n; ++i)
		cout << f(stairs[i]) << endl;

	return 0;
}
