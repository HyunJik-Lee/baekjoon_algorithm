#include <iostream>
#include <algorithm>
using namespace std;

int memo[1000001];

int f(long long n) {
	int c1 = 99999, c2 = 99999, c3;
	if (n == 1) return 0;
	if (memo[n] != 0) return memo[n];
	if (n % 3 == 0) c1 = f(n / 3) + 1;
	if (n % 2 == 0) c2 = f(n / 2) + 1;
	c3 = f(n - 1) + 1;
	memo[n] = min({ c1, c2, c3 });
	return memo[n];
}
int main() {
	long long n;
	cin >> n;
	cout << f(n);
}
